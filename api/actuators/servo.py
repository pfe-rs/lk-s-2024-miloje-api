from actuators.actuator import Actuator


class Servo(Actuator):
    """Class for controlling a servo motor"""
    def set_position(self, angle):
        self.communication.send(f"{self.id} {angle}")
