from Sensor import *
from Actuator import *
from Wheels import *
from Head import *
import time

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
        query = input("Insert a command: ")

        if query == "F":
            miloje.head.horizontal_angle(0)
            miloje.head.vertical_angle(90)
            sensorDistance = float(miloje.head.ultraSonicRead())
            for _ in range(10):
                if sensorDistance < 30:
                    sensorDistance = float(miloje.head.ultraSonicRead())
                if sensorDistance > 30:
                    miloje.wheels.forward(500, 10)
        elif query == "B":
            miloje.head.horizontal_angle(180)
            miloje.head.vertical_angle(90)
            sensorDistance = float(miloje.head.ultraSonicRead())
            for _ in range(10):
                if sensorDistance < 30:
                    sensorDistance = float(miloje.head.ultraSonicRead())
                if sensorDistance > 30:
                    miloje.wheels.backward(500, 10)
        elif query == "90":
            miloje.wheels.spinClockwise(100, 90)
        elif query == "45":
            miloje.wheels.spinClockwise(100, 45)
        elif query == "-90":
            miloje.wheels.spinAntiClockwise(100, 90)
        elif query == "-45":
            miloje.wheels.spinAntiClockwise(100, 45)

    while True:
        miloje.head.vertical_angle(0)
        time.sleep(1)
        miloje.head.vertical_angle(120)
        time.sleep(1)
        print(miloje.head.ultraSonicRead())
        time.sleep(0.5)