from communication.uart import UART
from miloje import Miloje

if __name__ == "__main__":
    comm = UART("/dev/ttyACM0", 9600, 1)
    miloje = Miloje(UART("/dev/ttyACM0", 9600, 1))

    wheels = miloje.get_wheels()
    head = miloje.get_head()

    if head:
        head.horizontal_angle(45)
        head.vertical_angle(0)

    if wheels:
        wheels.backward(5000, 5000)
