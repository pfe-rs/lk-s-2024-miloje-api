from sensors.sensor import Sensor


class Battery(Sensor):
    def get_data(self) -> float:
        """Get value (voltage) from the battery"""
        self.communication.send(f"{self.id}")
        return float(self.communication.receive())
