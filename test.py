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
    print(f"Read: {ser.read(12)}")
    ser.reset_input_buffer()

while True:
    test = int(input("Action: "))*2
    send_command(1,test)
    time.sleep(2)
    # send_command(1,test)
    # time.sleep(2)