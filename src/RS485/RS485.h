#pragma once
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "RS485/jauge.h"

#define RX_PIN DD3
#define TX_PIN DD4

#define Address_Jauge1 6
#define Address_Jauge2 7


class RS485 {
    private:
        SoftwareSerial Serial_RS485;
        Jauge _Jauge1;
        Jauge _Jauge2;  
    public:
        RS485();
        void setup();
        void read_pressure();
};
