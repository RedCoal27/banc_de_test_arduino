#code qui envois 1 puis 10 (valeur litérale) sur la liaison série (auto chercher arduino sur port série)

import serial
import time

ser = serial.Serial()
ser.baudrate = 9600
ser.port = 'COM3'
ser.open()
time.sleep(2)

while True:
    ser.write(b'0')
    ser.write(b'10')
    time.sleep(2)
    ser.write(b'0')
    ser.write(b'11')
    time.sleep(2)