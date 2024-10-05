from sensors.sensor import Sensor


class UltraSonic(Sensor):
    """Ultrasonic sensor class

    Args:
        communication (Communication): Communication object specifying the communication channel (UART/Bluetooth)
        sensor_id (int): Index of the capability in the capabilities list
    """
    def get_data(self) -> float:
        """Get value (distance) from the ultrasonic sensor

        Args:
            None

        Returns:
            float: Distance in cm
        """
        self.communication.send(f"{self.id}")
        return float(self.communication.receive())
