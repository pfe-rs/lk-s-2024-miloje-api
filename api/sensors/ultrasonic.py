from sensors.sensor import Sensor


class UltraSonic(Sensor):
    def get_data(self) -> float:
        """Get value (distance) from the ultrasonic sensor"""
        self.communication.send(f"{self.id}")
        return float(self.communication.receive())
