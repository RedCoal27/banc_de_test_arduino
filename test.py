#code qui envois 1 puis 10 (valeur litérale) sur la liaison série (auto chercher arduino sur port série)

import serial
import time

ser = serial.Serial()
ser.baudrate = 9600
ser.port = 'COM3'
ser.timeout = 0.5
ser.open()
time.sleep(2)

def send_command(type,action):
    ser.write(bytes([type]))
    time.sleep(0.01)
    ser.write(bytes([action]))
    print(f"Read: {ser.read(10)}")
    ser.reset_input_buffer()

while True:
    send_command(0,2)
    time.sleep(2)
    send_command(0,3)
    time.sleep(2)