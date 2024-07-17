from Sensor import *

class Miloje:
    def __init__(self,communication,capabilities):
        self.communication=communication
        self.capabilities=capabilities
    def get_actuators(self):
        return self.capabilities["actuators"]
    def get_sensors(self):
        return self.capabilities["sensors"]
    def get_head(self):
        return self.head["head"]
    def get_wheels(self):
        return self.wheels["wheels"]
    
