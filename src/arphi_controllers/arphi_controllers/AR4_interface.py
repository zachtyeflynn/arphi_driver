import rclpy
from rclpy.node import Node
from arphi_interfaces.msg import JointCommands
import serial

class AR4Interface(Node):

    # Constructor
    def __init__(self):

        super().__init__("enclosure_interface")

        self.subscriber_ = self.create_subscription(JointCommands, "joint_commands", self.receiverCallback, 10)
        self.timer_ = self.create_timer(1/30, self.serialCallback)
        self.ser_ = serial.Serial(port = "/dev/ttyACM0", baudrate = 115200)

        self.j1 = 0
        self.j2 = 0
        self.j3 = 0

        self.dj1 = 0
        self.dj2 = 0
        self.dj3 = 0
        
    def receiverCallback(self, msg: JointCommands):

        self.dj1 += msg.dj1
        self.dj2 += msg.dj2
        self.dj3 += msg.dj3

    def serialCallback(self):

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