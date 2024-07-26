from communication.communication import Communication


class Sensor:
    def __init__(self, communication: Communication, sensor_id: int):
        self.communication = communication
        self.id = sensor_id

    def get_data(self) -> str:
        return ""
