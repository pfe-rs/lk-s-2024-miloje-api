from Communication import Communication


class Actuator:
    '''Base Actuator class'''
    def __init__(self, communication: Communication, index: int):
        self.communication = communication
        self.index = index


class Stepper(Actuator):
    '''Class for controlling a stepper motor'''
    def __init__(self, communication: Communication, index: int):
        super().__init__(communication, index)

    def clockwise(self, speed: int, distance: int):
        self.communication.send(f"{self.index} F {round(speed * 7.87)} {round(distance * 7.87)}")

    def anticlockwise(self, speed: int, distance: int):
        self.communication.send(f"{self.index} B {round(speed * 7.87)} {round(distance * 7.87)}")


class Servo(Actuator):
    '''Class for controlling a servo motor'''
    def __init__(self, communication: Communication, index: int):
        super().__init__(communication, index)

    def setPosition(self, angle):
        self.communication.send(f"{self.index} {angle}")
