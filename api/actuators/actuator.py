from abc import ABC

from communication.communication import Communication


class Actuator(ABC):
    """Abstract Actuator class

    Args:
        communication (Communication): Communication object specifying the communication channel (UART/Bluetooth)
        actuator_id (int): Index of the capability in the capabilities list

    Attributes:
        communication (Communication): Communication object specifying the communication channel (UART/Bluetooth)
        id (int): Index of the capability in the capabilities list
    """
    def __init__(self, communication: Communication, actuator_id: int):
        self.communication = communication
        self.id = actuator_id
