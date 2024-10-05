from actuators.servo import Servo
from sensors.ultrasonic import UltraSonic


class Head:
    """MILOJE head class for controlling the head (two servos and one ultrasonic sensor)

    Args:
        servo1 (Servo): Servo 1
        servo2 (Servo): Servo 2
        ultra_sonic (UltraSonic): Ultrasonic sensor on MILOJE's head

    Attributes:
        servo1 (Servo): Servo 1
        servo2 (Servo): Servo 2
        ultra_sonic (UltraSonic): Ultrasonic sensor
    """
    def __init__(self, servo1: Servo, servo2: Servo, ultra_sonic: UltraSonic):
        self.servo1 = servo1
        self.servo2 = servo2
        self.ultra_sonic = ultra_sonic

    def horizontal_angle(self, angle: int):
        """Set horizontal angle (in degrees) of the head

        Args:
            angle (int): Angle in degrees
        """
        self.servo1.set_position(angle)

    def vertical_angle(self, angle: int):
        """Set vertical angle (in degrees) of the head

        Args:
            angle (int): Angle in degrees
        """
        self.servo2.set_position(angle)

    def ultrasonic_read(self) -> float:
        """Get value (distance) from the ultrasonic sensor

        Args:
            None

        Returns:
            float: Distance in cm
        """
        return self.ultra_sonic.get_data()
