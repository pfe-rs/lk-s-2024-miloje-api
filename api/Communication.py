import serial


class Communication():
    def __init__(self, baudRate: int):
        self.baudRate = baudRate

    def send(self, data):
        '''Send data to the communication channel'''
        pass

    def receive(self) -> str:
        '''Receive data from the communication channel'''
        return ''


class UART(Communication):
    def __init__(self, port: str, baudRate: int, timeout: int = 1):
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
        except Exception as err:
            print(f"Error: {err}")

    def send(self, data: str):
        '''Send data to the communication channel'''
        try:
            if not self.conn.is_open:
                raise Exception(f"Serial port {self.port} is not open.")

            self.conn.write(data.encode() + b'\n')

        except Exception as err:
            print(f"Error while sending: {err}")

    def receive(self) -> str:
        '''Receive data from the communication channel'''
        if not self.conn.is_open:
            raise Exception(f"Serial port {self.port} is not open.")

        data_bytes = self.conn.read_all()
        if data_bytes:
            return data_bytes.decode()
        else:
            return ''
