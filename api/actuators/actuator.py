from abc import ABC

from communication.communication import Communication


class Actuator(ABC):
    """Base Actuator class"""
    def __init__(self, communication: Communication, actuator_id: int):
        self.communication = communication
        self.id = actuator_id
