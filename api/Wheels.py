from Communication import *
from Actuator import Stepper

class Wheels:
    def __init__(self,communication,stepper1,stepper2):
        self.communication=communication
        self.stepper1=stepper1
        self.stepper2=stepper2
    def forward(self,speed,distance):
        self.stepper1.anticlockwise(speed,distance)
        self.stepper2.clockwise(speed,distance)
    def backward(self,speed,distance):
        self.stepper1.clockwise(speed,distance)
        self.stepper2.anticlockwise(speed,distance)
    def spinClockwise(self,speed,angle):
        self.stepper1.anticlockwise(speed,2/8*angle)
        self.stepper2.anticlockwise(speed,2/8*angle)
    def spinAntiClockwise(self,speed,angle):
        self.stepper1.clockwise(speed,2/8*angle)
        self.stepper2.clockwise(speed,2/8*angle)
          
