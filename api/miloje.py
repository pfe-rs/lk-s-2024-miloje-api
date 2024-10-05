from typing import List

from actuators.servo import Servo
from actuators.stepper import Stepper
from actuators.wheels import Wheels
from buzzer import Buzzer
from communication.communication import Communication
from head import Head
from sensors.battery import Battery
from sensors.ultrasonic import UltraSonic

CMD_CAPABILITIES = "C 1"
CAPABILITY_TYPES = {
    "M": Stepper,
    "S": Servo,
    "B": Battery,
    "U": UltraSonic,
    "Z": Buzzer
}


class Miloje:
    """MILOJE class for controlling the robot

    Args:
        communication (Communication): Communication object specifying the communication channel (UART/Bluetooth)

    Attributes:
        communication (Communication): Communication object specifying the communication channel (UART/Bluetooth)
        capabilities (dict): Dictionary of capabilities
        wheels (Wheels): Wheels object
        head (Head): Head object
    """
    def __init__(self, communication: Communication):
        self.communication = communication
        self.capabilities = {}
        self.wheels = None
        self.head = None

        self.communication.send(CMD_CAPABILITIES)
        data = self.communication.receive()
        for index, char in enumerate(data):
            if char not in self.capabilities and char.isalpha():
                self.capabilities[char] = []
            self.capabilities[char].append(CAPABILITY_TYPES[char](self.communication, index))

        try:
            self.wheels = Wheels(self.capabilities["M"][0],
                                 self.capabilities["M"][1])
        except IndexError:
            self.wheels = None

        try:
            self.head = Head(self.capabilities["S"][0],
                             self.capabilities["S"][1],
                             self.capabilities["U"][0])
        except IndexError:
            self.head = None

    def get_steppers(self) -> List[Stepper]:
        """Get steppers from the capabilities

        Args:
            None

        Returns:
            List[Stepper]: List of steppers found in MILOJE's capabilities
        """
        return self.capabilities["M"]

    def get_servos(self) -> List[Servo]:
        """Get servos from the capabilities

        Args:
            None

        Returns:
            List[Servo]: List of servos found in MILOJE's capabilities
        """
        return self.capabilities["S"]

    def get_head(self) -> Head | None:
        """Get the reference to MILOJE's head

        Args:
            None

        Returns:
            Head: Reference to MILOJE's head
        """
        return self.head

    def get_wheels(self) -> Wheels | None:
        """Get the reference to MILOJE's wheels

        Args:
            None

        Returns:
            Wheels: Reference to MILOJE's wheels
        """
        return self.wheels
