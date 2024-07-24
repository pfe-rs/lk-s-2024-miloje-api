from Sensor import Battery, UltraSonic
from Actuator import Stepper, Servo
from Wheels import Wheels
from Head import Head
from Communication import Communication


class Miloje:
    def __init__(self, communication: Communication):
        self.communication = communication

        # Receiving MILOJE capabilities
        self.communication.send("C")
        capabilityTypes = self.communication.receive()
        self.capabilities = {}
        for index, char in enumerate(capabilityTypes):
            if char not in self.capabilities and char.isalpha():
                self.capabilities[char] = []
            if char == "M":
                self.capabilities[char].append(Stepper(self.communication, index))
            if char == "S":
                self.capabilities[char].append(Servo(self.communication, index))
            if char == "B":
                self.capabilities[char].append(Battery(self.communication, index))
            if char == "U":
                self.capabilities[char].append(UltraSonic(self.communication, index))

        # MILOJE head
        self.wheels = Wheels(self.communication, self.capabilities["M"][0],
                             self.capabilities["M"][1])

        # MILOJE wheels
        self.head = Head(self.communication, self.capabilities["S"][0],
                         self.capabilities["S"][1], self.capabilities["U"][0])

    def get_actuators(self):
        return self.capabilities["actuators"]

    def get_sensors(self):
        return self.capabilities["sensors"]

    def get_head(self) -> Head:
        return self.head

    def get_wheels(self) -> Wheels:
        return self.wheels
