from actuators.servo import Servo
from sensors.ultrasonic import UltraSonic


class Head:
    def __init__(self, servo1: Servo, servo2: Servo, ultra_sonic: UltraSonic):
        self.servo1 = servo1
        self.servo2 = servo2
        self.ultra_sonic = ultra_sonic

    def horizontal_angle(self, angle: int):
        self.servo1.set_position(angle)

    def vertical_angle(self, angle: int):
        self.servo2.set_position(angle)

    def ultrasonic_read(self) -> str:
        return self.ultra_sonic.get_data()
