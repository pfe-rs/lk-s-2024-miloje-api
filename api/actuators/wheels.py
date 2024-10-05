from actuators.stepper import Stepper


class Wheels:
    """MILOJE wheels class for controlling the main wheels (two steppers defined in class Miloje)

    Args:
        stepper1 (Stepper): Stepper 1
        stepper2 (Stepper): Stepper 2
    """
    def __init__(self, stepper1: Stepper, stepper2: Stepper):
        self.stepper1 = stepper1
        self.stepper2 = stepper2

    def forward(self, speed: int, distance: int):
        """Move MILOJE forward

        Args:
            speed (int): Speed of the wheels
            distance (int): Distance the wheels need to move
        """
        self.stepper1.clockwise(speed, distance)
        self.stepper2.anticlockwise(speed, distance)

    def backward(self, speed: int, distance: int):
        """Move MILOJE backward

        Args:
            speed (int): Speed of the wheels
            distance (int): Distance the wheels need to move
        """
        self.stepper1.anticlockwise(speed, distance)
        self.stepper2.clockwise(speed, distance)

    def spin_clockwise(self, speed: int, angle: int):
        """Spin MILOJE in the clockwise direction

        Args:
            speed (int): Speed of the wheels
            angle (int): Angle in degrees
        """
        self.stepper1.anticlockwise(speed, (2*angle)//8)
        self.stepper2.anticlockwise(speed, (2*angle)//8)

    def spin_anticlockwise(self, speed: int, angle: int):
        """Spin MILOJE in the anticlockwise direction

        Args:
            speed (int): Speed of the wheels
            angle (int): Angle in degrees
        """
        self.stepper1.clockwise(speed, (2*angle)//8)
        self.stepper2.clockwise(speed, (2*angle)//8)
