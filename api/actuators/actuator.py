from communication.communication import Communication


class Actuator:
    """Base Actuator class"""
    def __init__(self, communication: Communication, actuator_id: int):
        self.communication = communication
        self.id = actuator_id
