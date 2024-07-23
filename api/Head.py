from Communication import *
from Actuator import Servo
from Sensor import UltraSonic

class Head:
    def __init__(self,communication,servo1,servo2,ultraSonic):
        self.communication=communication
        self.servo1=servo1
        self.servo2=servo2
        self.ultraSonic=ultraSonic
    def horizontal_angle(self,angle):
        self.servo1.setPosition(angle)
    def vertical_angle(self,angle):
        self.servo2.setPosition(angle)
    def ultraSonicRead(self):
        return self.ultraSonic.get_data()
    