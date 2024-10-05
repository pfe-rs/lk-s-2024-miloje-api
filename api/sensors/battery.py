from sensors.sensor import Sensor


class Battery(Sensor):
    """Battery sensor class

    Args:
        communication (Communication): Communication object specifying the communication channel (UART/Bluetooth)
        sensor_id (int): Index of the capability in the capabilities list
    """
    def get_data(self) -> float:
        """Get value (voltage) from the battery

        Args:
            None

        Returns:
            float: Voltage in Volts
        """
        self.communication.send(f"{self.id}")
        return float(self.communication.receive())
