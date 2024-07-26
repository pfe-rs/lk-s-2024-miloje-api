from actuators.actuator import Actuator


class Stepper(Actuator):
    """Class for controlling a stepper motor"""
    def clockwise(self, speed: int, distance: int):
        self.communication.send(f"{self.id} {round(speed * 7.87)} {round(distance * 7.87)}")

    def anticlockwise(self, speed: int, distance: int):
        self.communication.send(f"{self.id} {round(speed * 7.87)} {round(distance * 7.87)}")
