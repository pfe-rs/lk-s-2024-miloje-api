from Communication import *

class actuator:
    def __init__(self,communication):
        self.communication=communication
class stepper(actuator):
    def __init__(self,communication):
        super().__init__(communication)
    def clockwise(self,distance,speed):
        self.communication.send(f"M 2 {distance * 7.87} {speed*7.87}")
    def anticlockwise(self,distance,speed):
        self.communication.send(f"M 2 {distance * -7.87} {speed*-7.87}")
class servo(actuator):
    def __init__(self,communication):
        super().__init__(communication)
    def setPosition(self,angle):
        self.communication.send(f"M 1 {angle}")
        