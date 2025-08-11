import rclpy
from rclpy.node import Node
from arphi_interfaces.msg import StepperCommands
from sensor_msgs.msg import JointState
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
import pygame
import numpy as np

class JointPublisher(Node):
    def __init__(self):
        super().__init__("joint_trajectory_broadcaster")

        pygame.init()
        pygame.joystick.init()
        self.joystick = pygame.joystick.Joystick(0)
        self.joystick.init()

        self.create_subscription(JointState, "joint_states", self.update_joint_states, 10)
        self.AR4_publisher_ = self.create_publisher(JointTrajectory, "joint_trajectory_controller/joint_trajectory", 10)
        self.arphi_publisher_ = self.create_publisher(StepperCommands, "stepper_commands", 10)

        self.create_timer(1/30, self.mode_update)

        self.create_timer(1/60, self.publish_commands)

        self.joint_states_position = np.zeros(3)

        self.AR4_controller_modes = ["all_joints", "joint_1", "joint_2", "joint_3"]
        self.AR4_mode_dictionary = {"all_joints": [1, 1, 1], "joint_1": [1, 0, 0], "joint_2": [0, 1, 0], "joint_3": [0, 0, 1]}
        self.arphi_controller_modes = ["all_steppers", "stepper_1", "stepper_2", "stepper_3"]
        self.arphi_mode_dictionary = {"all_steppers": [1, 1, 1], "stepper_1": [1, 0, 0], "stepper_2": [0, 1, 0], "stepper_3": [0, 0, 1]}

        self.AR4_control = 1
        
        self.AR4_current_mode = 0
        print("Current AR4 mode: ", self.AR4_controller_modes[self.AR4_current_mode])
        self.arphi_current_mode = 0
        print("Current ARPHI mode: ", self.arphi_controller_modes[self.arphi_current_mode])

        self.change_speed = 0.02
        self.min_speed = 0.01
        self.max_speed = 0.05
        self.sweep_speed = 0.001

    def update_joint_states(self, msg: JointState):

        self.joint_states_position = np.array(msg.position[:3])

    def mode_update(self):

        pygame.event.pump()

        switch_robot_pressed = self.joystick.get_button(5)

        switch_mode_pressed = self.joystick.get_button(0)

        if switch_robot_pressed and not getattr(self, "_last_robot", False):
            self.AR4_control = (self.AR4_control + 1) % 2
            self.joystick.rumble(1, 1, 200)
            print("Controlling AR4: ", self.AR4_control == 1)

        if switch_mode_pressed and not getattr(self, "_last_mode", False):

            if self.AR4_control == 1:

                self.AR4_current_mode = (self.AR4_current_mode + 1) % len(self.AR4_controller_modes)
                print("Switching AR4 mode to: ", self.AR4_controller_modes[self.AR4_current_mode])

            elif self.AR4_control == 0:

                self.arphi_current_mode = (self.arphi_current_mode + 1) % len(self.arphi_controller_modes)
                print("Switching ARPHI mode to: ", self.arphi_controller_modes[self.arphi_current_mode])

        # Store states for next cycle
        self._last_robot = switch_robot_pressed
        self._last_mode = switch_mode_pressed

        down_speed = self.joystick.get_button(6)
        up_speed = self.joystick.get_button(7)

        if self.AR4_control == 1:

            if down_speed == 1 or up_speed == 1:

                requested_speed = self.change_speed - self.sweep_speed*down_speed + self.sweep_speed*up_speed

                if requested_speed >= self.min_speed and requested_speed <= self.max_speed:

                    self.change_speed = requested_speed

    def publish_commands(self):

        if self.AR4_control == 1:

            AR4_mode = self.AR4_controller_modes[self.AR4_current_mode]
            AR4_actuated_joints = self.AR4_mode_dictionary[AR4_mode]

            if AR4_actuated_joints[0] == 1:
                dj1 = self.change_speed * self.joystick.get_axis(0)
            else:
                dj1 = 0
            if AR4_actuated_joints[1] == 1:
                dj2 = self.change_speed * self.joystick.get_axis(1)
            else:
                dj2 = 0
            if AR4_actuated_joints[2] == 1:
                dj3 = self.change_speed * self.joystick.get_axis(4)
            else:
                dj3 = 0

            new_positions = self.joint_states_position + np.array([dj1, dj2, dj3])

            trajectory = JointTrajectory()
            trajectory.joint_names = ["joint_1", "joint_2", "joint_3"]

            point1 = JointTrajectoryPoint()
            point1.positions = self.joint_states_position.tolist()
            point1.velocities = [0.0] * 3
            point1.time_from_start.sec = 0
            point1.time_from_start.nanosec = 0

            point2 = JointTrajectoryPoint()
            point2.positions = new_positions.tolist()
            point2.velocities = [0.0] * 3
            point2.time_from_start.sec = 0
            point2.time_from_start.nanosec = int(1e9 / 60)  # 1/60 second

            trajectory.points = [point1, point2]

            self.AR4_publisher_.publish(trajectory)
        
        elif self.AR4_control == 0:

            arphi_mode = self.arphi_controller_modes[self.arphi_current_mode]
            arphi_actuated_steppers = self.arphi_mode_dictionary[arphi_mode]

            if arphi_actuated_steppers[0] == 1:
                ds1 = int(round(5 * self.joystick.get_axis(0), 0))
            else:
                ds1 = 0
            if arphi_actuated_steppers[1] == 1:
                ds2 = -int(round(5 * self.joystick.get_axis(1), 0))
            else:
                ds2 = 0
            if arphi_actuated_steppers[2] == 1:
                ds3 = -int(round(5 * self.joystick.get_axis(4), 0))
            else:
                ds3 = 0

            msg = StepperCommands()
            msg.ds1 = ds1
            msg.ds2 = ds2
            msg.ds3 = ds3

            self.arphi_publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = JointPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()