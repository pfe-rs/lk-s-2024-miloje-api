from sensors.sensor import Sensor


class UltraSonic(Sensor):
    def get_data(self) -> str:
        """Get value (distance) from the ultrasonic sensor"""
        self.communication.send(f"{self.id}")
        return self.communication.receive()
