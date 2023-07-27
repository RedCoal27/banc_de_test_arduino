#pragma once
#include <Arduino.h>
#include <SoftwareSerial.h>

#define PRESSURE_UNIT 1 //mbar

class Jauge {
    private:
        SoftwareSerial* Serial_RS485;
        String query(uint8_t address);
    public:
        Jauge(SoftwareSerial* Serial_RS485);
        String send_command(uint8_t address, String command);
};
