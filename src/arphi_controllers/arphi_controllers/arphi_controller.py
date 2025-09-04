import rclpy
#import time
from rclpy.node import Node
from arphi_interfaces.msg import JointCommands
from arphi_interfaces.msg import StepperCommands
#from sensor_msgs.msg import JointState
#from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
import pygame
#import numpy as np

class JointPublisher(Node):
    def __init__(self):
        super().__init__("joint_trajectory_broadcaster")

        # Start joystick
        pygame.init()
        pygame.joystick.init()
        self.joystick = pygame.joystick.Joystick(0)
        self.joystick.init()

        # Create publisher to joint_commands & stepper_commands
        self.AR4_publisher_ = self.create_publisher(JointCommands, "joint_commands", 10)
        self.arphi_publisher_ = self.create_publisher(StepperCommands, "stepper_commands", 10)

        # Update the commands modes every 60 hz, if necessary
        self.create_timer(1/60, self.mode_update)
        
        # Publish commands to topics
        self.create_timer(1/60, self.publish_commands)

        # Define the different control modes you can cycle through
        self.AR4_controller_modes = ["all_joints", "joint_1", "joint_2", "joint_3"]
        self.AR4_mode_dictionary = {"all_joints": [1, 1, 1], "joint_1": [1, 0, 0], "joint_2": [0, 1, 0], "joint_3": [0, 0, 1]}
        self.arphi_controller_modes = ["all_steppers", "stepper_1", "stepper_2", "stepper_3"]
        self.arphi_mode_dictionary = {"all_steppers": [1, 1, 1], "stepper_1": [1, 0, 0], "stepper_2": [0, 1, 0], "stepper_3": [0, 0, 1]}

        # Set to controlling AR4 to begin with (1 = controlling AR4, 0 = controlling ARPHI bioprinter)
        self.AR4_control = 1
        
        # Set the current AR4 control mode to controlling all joints
        self.AR4_current_mode = 0
        print("Current AR4 mode: ", self.AR4_controller_modes[self.AR4_current_mode])
        # Set the current ARPHI control mode to controlling all steppers
        self.arphi_current_mode = 0
        print("Current ARPHI mode: ", self.arphi_controller_modes[self.arphi_current_mode])

        # Set the min and max speed, as well as how fast you can sweep through different speeds
        self.change_speed = 0.02
        self.min_speed = 0.01
        self.max_speed = 0.05
        self.sweep_speed = 0.0001

    def rumble_controller(self):

        self.joystick.rumble(low_frequency=0.2, high_frequency=1, duration=200)

    def mode_update(self):

        # Check whether buttons were pressed to change the control modes

        pygame.event.pump()

        # Switch between controlling AR4 and ARPHI (R1)
        switch_robot_pressed = self.joystick.get_button(5)

        # Cycle through controlling the different joints/steppers (X)
        switch_mode_pressed = self.joystick.get_button(0)

        # Rumble controller when switching between AR4 and ARPHI
        if switch_robot_pressed and not getattr(self, "_last_robot", False):
            self.AR4_control = (self.AR4_control + 1) % 2
            self.rumble_controller()
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

        # Sweep through different speeds (L2 and R2)
        down_speed = self.joystick.get_button(6)
        up_speed = self.joystick.get_button(7)

        # If min or max speed is reached, then don't allow the speed to go any below or above limit
        if self.AR4_control == 1:

            if down_speed == 1 or up_speed == 1:

                requested_speed = self.change_speed - self.sweep_speed*down_speed + self.sweep_speed*up_speed

                if requested_speed >= self.min_speed and requested_speed <= self.max_speed:

                    self.change_speed = requested_speed

    def publish_commands(self):

        # If controlling AR4
        if self.AR4_control == 1:

            AR4_mode = self.AR4_controller_modes[self.AR4_current_mode]
            AR4_actuated_joints = self.AR4_mode_dictionary[AR4_mode]

            # Publish to joint_commands topic
            if AR4_actuated_joints[0] == 1:
                dj1 = int(round(5 * self.joystick.get_axis(0), 0))
            else:
                dj1 = 0
            if AR4_actuated_joints[1] == 1:
                dj2 = -int(round(5 * self.joystick.get_axis(1), 0))
            else:
                dj2 = 0
            if AR4_actuated_joints[2] == 1:
                dj3 = -int(round(5 * self.joystick.get_axis(4), 0))
            else:
                dj3 = 0

            msg = JointCommands()
            msg.dj1 = dj1
            msg.dj2 = dj2
            msg.dj3 = dj3

            self.AR4_publisher_.publish(msg)
        
        # If controlling ARPHI
        elif self.AR4_control == 0:

            arphi_mode = self.arphi_controller_modes[self.arphi_current_mode]
            arphi_actuated_steppers = self.arphi_mode_dictionary[arphi_mode]

            # Publish to stepper_commands topic
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