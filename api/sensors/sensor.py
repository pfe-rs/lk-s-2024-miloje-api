from abc import ABC, abstractmethod

from communication.communication import Communication


class Sensor(ABC):
    def __init__(self, communication: Communication, sensor_id: int):
        self.communication = communication
        self.id = sensor_id

    @abstractmethod
    def get_data(self) -> str | float:
        return ""
