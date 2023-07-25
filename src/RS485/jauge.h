#pragma once
#include <Arduino.h>
#include <SoftwareSerial.h>

#define PRESSURE_UNIT 1 //mbar

class Jauge {
    private:
        SoftwareSerial* Serial_RS485;
        byte _address;
        String query;
    public:
        Jauge(SoftwareSerial* Serial_RS485, byte address);
        void setup();
        uint16_t read_pressure();
        String send_command(String command);
};
