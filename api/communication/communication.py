from abc import ABC, abstractmethod


class Communication(ABC):
    """Abstract Communication class"""
    @abstractmethod
    def send(self, data):
        """Send data to the communication channel

        Args:
            data (str): Data to be sent

        Returns:
            None
        """
        pass

    @abstractmethod
    def receive(self) -> str:
        """Receive data from the communication channel

        Args:
            None

        Returns:
            str: Received data
        """
        return ""
