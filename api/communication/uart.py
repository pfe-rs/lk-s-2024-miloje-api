import time

import serial
from communication.communication import Communication


class UART(Communication):
    """UART communication channel

    Args:
        port (str): Port of the UART communication channel
        baud_rate (int): Baud rate of the UART communication channel
        timeout (int | None, optional): Timeout of the UART communication channel. Defaults to None.

    Attributes:
        baud_rate (int): Baud rate of the UART communication channel
        port (str): Port of the UART communication channel
        conn (serial.Serial): Serial connection to the UART communication channel
    """
    def __init__(self, port: str, baud_rate: int, timeout: int | None = None):
        self.baud_rate = baud_rate
        self.port = port
        self.conn = serial.Serial(
            port=self.port,
            baudrate=self.baud_rate,
            timeout=timeout
        )
        time.sleep(1)

    def send(self, data: str):
        """Send data to the communication channel

        Args:
            data (str): Data to be sent
        """
        self.conn.write(data.encode() + b"\n")

    def receive(self) -> str:
        """Receive data from the communication channel

        Args:
            None

        Returns:
            str: Received data
        """
        data = self.conn.read_all()
        if data is not None:
            data = data.decode()
        else:
            while data is None or len(data) == 0:
                time.sleep(0.5)
                data = self.conn.read_all()
                if data is not None:
                    data = data.decode()
        return data.strip()
