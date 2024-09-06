import serial
import time
from communication.communication import Communication


class UART(Communication):
    def __init__(self, port: str, baud_rate: int, timeout: int | None = None):
        self.baud_rate = baud_rate
        self.port = port
        self.conn = serial.Serial(
            port=self.port,
            baudrate=self.baud_rate,
            bytesize=serial.EIGHTBITS,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            timeout=timeout
        )
        time.sleep(1)

    def send(self, data: str):
        """Send data to the communication channel"""
        self.conn.write(data.encode() + b"\n")

    def receive(self) -> str:
        """Receive data from the communication channel"""
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
