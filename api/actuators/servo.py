from actuators.actuator import Actuator


class Servo(Actuator):
    """Class for controlling a servo motor

    Args:
        communication (Communication): Communication object specifying the communication channel (UART/Bluetooth)
        actuator_id (int): Index of the capability in the capabilities list
    """
    def set_position(self, angle):
        """Set angle (in degrees) for the servo motor

        Args:
            angle (int): Angle in degrees
        """
        self.communication.send(f"{self.id} {angle}")
