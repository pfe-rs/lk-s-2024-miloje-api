from Sensor import *
from Actuator import *

class Miloje:
    def __init__(self,communication):
        self.communication = communication
        self.communication.send("C")
        capabilityTypes = self.communication.receive()
        
        self.capabilities = {}  
        
        for index, char in enumerate(capabilityTypes):
            if char not in self.capabilities:
                self.capabilities[char] = [] 
            if(char=="M"):
                self.capabilities[char].append(Stepper(self.communication,index))
            if(char=="S"):
                self.capabilities[char].append(Servo(self.communication,index))
            if(char=="B"):
                self.capabilities[char].append(Battery(self.communication,index))
            if(char=="U"):
                self.capabilities[char].append(UltraSonic(self.communication,index))

    def get_actuators(self):
        return self.capabilities["actuators"]
    def get_sensors(self):
        return self.capabilities["sensors"]
    def get_head(self):
        return self.head["head"]
    def get_wheels(self):
        return self.wheels["wheels"]
    
if __name__ == '__main__':
    uart = UART("/dev/rfcomm0", 9600)
    miloje=Miloje(uart)
    #miloje.capabilities["S"][0].setPosition(0)
    print(miloje.capabilities["U"][0].get_data())
    while True:
        query = str(input("Give MILOJE an instruction: "))
        uart.send(query)

