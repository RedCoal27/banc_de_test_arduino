#pragma once
#include <Arduino.h>
#include "Wire.h"

#define ADDRESS_THROTTLE 0x01

#define SENSORS 0x01 //sensore register
#define POSITION 0x02    //position register

class ThrottleValve {
    private:
        uint8_t _chipAddr;
    public:
        ThrottleValve(uint8_t chipAddr);
        ~ThrottleValve();
        void set_position(uint16_t new_position);
        int get_sensor();
        int get_position();
        void command(uint8_t action);
        int read(uint8_t _register);
};