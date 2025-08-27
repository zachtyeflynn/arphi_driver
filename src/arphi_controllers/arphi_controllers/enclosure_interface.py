import rclpy
from rclpy.node import Node
from arphi_interfaces.msg import StepperCommands
import serial

class EnclosureInterface(Node):

    # Constructor
    def __init__(self):

        super().__init__("enclosure_interface")

        self.subscriber_ = self.create_subscription(StepperCommands, "stepper_commands", self.receiverCallback, 10)
        self.timer_ = self.create_timer(1/30, self.serialCallback)
        self.ser_ = serial.Serial(port = "/dev/ttyUSB0", baudrate = 9600)

        self.s1 = 0
        self.s2 = 0
        self.s3 = 0

        self.ds1 = 0
        self.ds2 = 0
        self.ds3 = 0
        
    def receiverCallback(self, msg: StepperCommands):

        self.ds1 += msg.ds1
        self.ds2 += msg.ds2
        self.ds3 += msg.ds3

    def serialCallback(self):

        self.s1 += self.ds1
        self.s2 += self.ds2
        self.s3 += self.ds3

        string = f"{self.ds1},{self.ds2},{self.ds3}\n"
        print(string)
        self.ser_.write(string.encode('utf-8'))

        self.ds1 = 0
        self.ds2 = 0
        self.ds3 = 0

def main(args=None):

    rclpy.init(args=args)
    node = EnclosureInterface()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":

    main()