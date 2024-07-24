from Communication import Communication
from Actuator import Stepper


class Wheels:
    def __init__(self, communication: Communication, stepper1: Stepper, stepper2: Stepper):
        self.communication = communication
        self.stepper1 = stepper1
        self.stepper2 = stepper2

    def forward(self, speed: int, distance: int):
        '''Move MILOJE forward'''
        self.stepper1.anticlockwise(speed, distance)
        self.stepper2.clockwise(speed, distance)

    def backward(self, speed: int, distance: int):
        '''Move MILOJE backward'''
        self.stepper1.clockwise(speed, distance)
        self.stepper2.anticlockwise(speed, distance)

    def spinClockwise(self, speed: int, angle: int):
        '''Spin MILOJE in the clockwise direction'''
        self.stepper1.anticlockwise(speed, (2*angle)//8)
        self.stepper2.anticlockwise(speed, (2*angle)//8)

    def spinAntiClockwise(self, speed: int, angle: int):
        '''Spin MILOJE in the anticlockwise direction'''
        self.stepper1.clockwise(speed, (2*angle)//8)
        self.stepper2.clockwise(speed, (2*angle)//8)
