from actuators.actuator import Actuator


class Stepper(Actuator):
    """Class for controlling a stepper motor

    Args:
        communication (Communication): Communication object specifying the communication channel (UART/Bluetooth)
        actuator_id (int): Index of the capability in the capabilities list
    """
    def clockwise(self, speed: int, distance: int):
        """Move stepper motor in the clockwise direction

        Args:
            speed (int): Speed of the stepper motor
            distance (int): Distance the stepper motor need to move
        """
        self.communication.send(f"{self.id} F {round(speed * 7.87)} {round(distance * 7.87)}")

    def anticlockwise(self, speed: int, distance: int):
        """Move stepper motor in the anticlockwise direction

        Args:
            speed (int): Speed of the stepper motor
            distance (int): Distance the stepper motor need to move
        """
        self.communication.send(f"{self.id} B {round(speed * 7.87)} {round(distance * 7.87)}")
