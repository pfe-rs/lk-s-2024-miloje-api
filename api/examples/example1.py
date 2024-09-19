from communication.uart import UART
from miloje import Miloje


if __name__ == "__main__":
    miloje = Miloje(UART("/dev/rfcomm0", 9600, 1))

    wheels = miloje.get_wheels()
    head = miloje.get_head()

    if wheels:
        while True:
            query = input("? ")
            if query == "w":
                wheels.forward(500, 212)
            elif query == "s":
                wheels.backward(500, 212)
            elif query == "a":
                wheels.spin_anticlockwise(300, 30)
            elif query == "d":
                wheels.spin_clockwise(300, 30)
