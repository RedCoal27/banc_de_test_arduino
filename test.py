#code qui envois 1 puis 10 (valeur litérale) sur la liaison série (auto chercher arduino sur port série)

import serial
import time

ser = serial.Serial()
ser.baudrate = 9600
ser.port = 'COM3'
ser.timeout = 1
ser.open()
time.sleep(2)

def send_command(type, action):
    ser.write(bytes([type]))
    time.sleep(0.01)
    ser.write(bytes([action]))
    data = ser.read(4)
    binary_data = [bin(byte) for byte in data]
    print(f"Read: {binary_data}")
    ser.reset_input_buffer()

while True:
    # test = int(input("Action: "))*2
    # for i in [1,2,3,4,5,6,7,8,9,20,14,15,16,17,26]:
    #     test = i*2
    #     print(test)
    #     send_command(0,test)
    #     time.sleep(3)
    #     print(test+1)
    #     send_command(0,test+1)
    #     time.sleep(2)
    send_command(1,0)
    time.sleep(2)