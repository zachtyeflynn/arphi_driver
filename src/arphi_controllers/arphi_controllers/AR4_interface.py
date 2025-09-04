import rclpy
from rclpy.node import Node
from arphi_interfaces.msg import JointCommands
import serial

class AR4Interface(Node):

    # Constructor
    def __init__(self):

        super().__init__("enclosure_interface")

        # Subscribe to joint_commands topic
        self.subscriber_ = self.create_subscription(JointCommands, "joint_commands", self.receiverCallback, 10)
        # Publish to serial 30 times a second
        self.timer_ = self.create_timer(1/30, self.serialCallback)
        # Start serial communication, baud rate = 115200
        self.ser_ = serial.Serial(port = "/dev/ttyACM0", baudrate = 115200)

        # Step coordinates since node has started
        self.j1 = 0
        self.j2 = 0
        self.j3 = 0

        # Increment of steps received from the controller
        self.dj1 = 0
        self.dj2 = 0
        self.dj3 = 0
        
    def receiverCallback(self, msg: JointCommands):

        # When a message is published to joint_commands, extract message

        self.dj1 += msg.dj1
        self.dj2 += msg.dj2
        self.dj3 += msg.dj3

    def serialCallback(self):
        
        # Send step commands via serial

        self.j1 += self.dj1
        self.j2 += self.dj2
        self.j3 += self.dj3 

        string = f"{self.dj1},{self.dj2},{self.dj3}\n"
        print(string)
        self.ser_.write(string.encode('utf-8'))

        self.dj1 = 0
        self.dj2 = 0
        self.dj3 = 0

def main(args=None):

    rclpy.init(args=args)
    node = AR4Interface()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":

    main()