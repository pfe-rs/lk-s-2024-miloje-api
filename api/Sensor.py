from Communication import Communication


class Sensor:
    def __init__(self, communication: Communication, index: int):
        self.communication = communication
        self.index = index

    def get_data(self) -> str:
        return ''


class UltraSonic(Sensor):
    def __init__(self, communication: Communication, index: int):
        super().__init__(communication, index)

    def get_data(self) -> str:
        '''Get value (distance) from the ultrasonic sensor'''
        self.communication.send(f"{self.index}")
        return self.communication.receive()


class Battery(Sensor):
    def __init__(self, communication: Communication, index: int):
        super().__init__(communication, index)

    def get_data(self) -> str:
        '''Get value (voltage) from the battery'''
        self.communication.send(f"{self.index}")
        return self.communication.receive()
