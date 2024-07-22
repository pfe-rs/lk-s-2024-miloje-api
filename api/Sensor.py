from Communication import *

class Sensor:
    def __init__(self, communication):
        self.communication = communication

    def get_data():
        ...

class UltraSonic(Sensor):
    def __init__(self,communication):
        super().__init__(communication)

    def get_data(self):
        self.communication.send("S")
        return self.communication.receive()

def test():
    comm= UART("/dev/ttyACM0", 9600)
    ultrasonic=UltraSonic(comm)
    print(ultrasonic.get_data())