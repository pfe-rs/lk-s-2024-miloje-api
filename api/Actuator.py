from Communication import *

class Actuator:
    def __init__(self,communication,index):
        self.communication=communication
        self.index=index

class Stepper(Actuator):
    def __init__(self,communication,index):
        super().__init__(communication,index)

    def clockwise(self,speed,distance):
        #print(distance)
        self.communication.send(f"{self.index} F {round(speed*7.87)} {round(distance*7,87)}") #distance in cm and speed in cm/s
        #print(f"{self.index} F {round(speed*7,87)} {round(distance*7.87)}")

    def anticlockwise(self,speed,distance):
        self.communication.send(f"{self.index} F {round(speed*7.87)} {round(-distance*7,87)}")

class Servo(Actuator):
    def __init__(self,communication,index):
        super().__init__(communication,index)

    def setPosition(self,angle):
        self.communication.send(f"{self.index} {angle}")
        