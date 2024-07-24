from Sensor import *
from Actuator import *
from Wheels import *
from Head import *
import time
import keyboard

class Miloje:
    def __init__(self,communication):
        self.communication = communication
        print("a")
        self.communication.send("C")
        print("b")
        capabilityTypes = self.communication.receive()
        print("c")
        print(capabilityTypes)
        self.capabilities = {}  
        
        for index, char in enumerate(capabilityTypes):
            if char not in self.capabilities and char.isalpha():
                self.capabilities[char] = [] 
            if(char=="M"):
                self.capabilities[char].append(Stepper(self.communication,index))
            if(char=="S"):
                self.capabilities[char].append(Servo(self.communication,index))
            if(char=="B"):
                self.capabilities[char].append(Battery(self.communication,index))
            if(char=="U"):
                self.capabilities[char].append(UltraSonic(self.communication,index))
        print(self.capabilities)
        self.wheels=Wheels(self.communication,self.capabilities["M"][0],self.capabilities["M"][1])
        
        self.head=Head(self.communication,self.capabilities["S"][0],self.capabilities["S"][1],self.capabilities["U"][0])

    def get_actuators(self):
        return self.capabilities["actuators"]
    def get_sensors(self):
        return self.capabilities["sensors"]
    def get_head(self):
        return self.head["head"]
    def get_wheels(self):
        return self.wheels["wheels"]
    
if __name__ == '__main__':
    miloje=Miloje(UART("/dev/rfcomm0", 9600))


    miloje.head.horizontal_angle(0)
    miloje.head.vertical_angle(0)

    while True:
        if keyboard.is_pressed('w'):
            miloje.wheels.forward(900, 10)
        elif keyboard.is_pressed('a'):
            miloje.wheels.spinAntiClockwise(100, 10)
        elif keyboard.is_pressed('s'):
            miloje.wheels.backward(900, 10)
        elif keyboard.is_pressed('d'):
            miloje.wheels.spinClockwise(100, 10)