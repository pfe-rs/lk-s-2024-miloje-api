from Communication import *

class Sensor:
    def __init__(self, communication,index):
        self.communication = communication
        self.index=index

    def get_data():
        ...

class UltraSonic(Sensor):
    def __init__(self,communication,index):
        super().__init__(communication,index)
    def get_data(self):
        self.communication.send(f"{self.index}")
        return self.communication.receive()

class Battery(Sensor):
    def __init__(self,communication,index):
        super().__init__(communication,index)
    def get_data(self):
        self.communication.send(f"{self.index}")
        return self.communication.receive()

def test():
    comm= UART("/dev/ttyACM0", 9600)
    ultrasonic=UltraSonic(comm)
    print(ultrasonic.get_data())