#code qui envois 1 puis 10 (valeur litérale) sur la liaison série (auto chercher arduino sur port série)

import serial
import time

ser = serial.Serial()
ser.baudrate = 9600
ser.port = 'COM3'
ser.timeout = 1
ser.open()
time.sleep(2)

while True:
    ser.write(bytes(0))
    ser.write(bytes(2))
    print(ser.read(1))
    time.sleep(2)
    ser.write(bytes(0))
    ser.write(bytes(3))
    print(ser.read(1))
    time.sleep(2)