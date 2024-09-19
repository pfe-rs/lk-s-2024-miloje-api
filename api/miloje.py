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
        return self.capabilities["M"]

    def get_servos(self) -> List[Servo]:
        return self.capabilities["S"]

    def get_head(self) -> Head | None:
        return self.head

    def get_wheels(self) -> Wheels | None:
        return self.wheels
