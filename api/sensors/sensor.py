from abc import ABC, abstractmethod

from communication.communication import Communication


class Sensor(ABC):
    """Abstract Sensor class

    Args:
        communication (Communication): Communication object specifying the communication channel (UART/Bluetooth)
        sensor_id (int): Index of the capability in the capabilities list
    """
    def __init__(self, communication: Communication, sensor_id: int):
        self.communication = communication
        self.id = sensor_id

    @abstractmethod
    def get_data(self) -> str | float:
        """Get value from the sensor

        Args:
            None

        Returns:
            str | float: Value from the sensor
        """
        return ""
