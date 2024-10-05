from abc import ABC, abstractmethod


class Communication(ABC):
    @abstractmethod
    def send(self, data):
        """Send data to the communication channel"""
        pass

    @abstractmethod
    def receive(self) -> str:
        """Receive data from the communication channel"""
        return ""
