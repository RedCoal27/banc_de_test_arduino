#pragma once
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "RS485/jauge.h"

#define RX_PIN DD3
#define TX_PIN DD4

#define Address_Jauge1 6


class RS485 {
    private:
        SoftwareSerial Serial_RS485;
        Jauge _Jauge1;
    public:
        RS485();
        void read_pressure();
};
