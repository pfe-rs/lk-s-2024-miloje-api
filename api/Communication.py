import serial
import time

class Communication():
    def __init__(self, baudRate):
        self.baudRate = baudRate

    def send(self, data):
        """Send data to the communication channel"""
        pass
    
    def receive(self):
        """Receive data from the communication channel"""
        pass

class UART(Communication):
    def __init__(self, port, baudRate, timeout=1):
        super().__init__(baudRate)
        self.port = port
        self.byteSize = serial.EIGHTBITS
        self.parity = serial.PARITY_NONE
        self.stopBits = serial.STOPBITS_ONE
        self.timeout = timeout
        try:
            self.conn = serial.Serial(
                port=self.port,
                baudrate=self.baudRate,
                bytesize=self.byteSize,
                parity=self.parity,
                stopbits=self.stopBits,
                timeout=self.timeout
            )
        except:
            print(f"Error while opening port {self.port}")

    def send(self, data):
        """Send data to the communication channel"""
        try:
            if not self.conn.is_open:
                raise Exception(f"Serial port {self.port} is not open.")
            
            self.conn.write(data.encode() + b'\n')

        except Exception as err:
            print(f"Error while sending: {err}")
    
    def receive(self):
        """Receive data from the communication channel"""
        try:
            if not self.conn.is_open:
                raise Exception(f"Serial port {self.port} is not open.")
            data = self.conn.read_all().decode()
            while len(data) == 0:
                data = self.conn.read_all().decode()
                time.sleep(0.2)
            return data
        except Exception as err:
            print(f"Error while receiving: {err}")
            return None


if __name__ == '__main__':
    uart = UART("/dev/ttyACM0", 9600)
    
    while True:
        query = str(input("Give MILOJE an instruction: "))
        uart.send(query)
