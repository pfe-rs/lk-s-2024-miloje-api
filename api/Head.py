from Communication import Communication
from Actuator import Servo
from Sensor import UltraSonic


class Head:
    def __init__(self, communication: Communication, servo1: Servo, servo2: Servo, ultraSonic: UltraSonic):
        self.communication = communication
        self.servo1 = servo1
        self.servo2 = servo2
        self.ultraSonic = ultraSonic

    def horizontal_angle(self, angle: int):
        self.servo1.setPosition(angle)

    def vertical_angle(self, angle: int):
        self.servo2.setPosition(angle)

    def ultraSonicRead(self) -> str:
        return self.ultraSonic.get_data()
