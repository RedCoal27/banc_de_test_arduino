#pragma once
#include <Arduino.h>
#include "Wire.h"

#define ADDRESS_THROTTLE 0x01

#define POSITION 0x01    //position register
#define SENSORS 0x02 //sensore register
#define DELTA_HOME 0x03 //delta home register
#define TENSION 0x04 //tension goes from 0x04 to 0x07

class ThrottleValve {
    private:
        uint8_t _chipAddr;
    public:
        ThrottleValve(uint8_t chipAddr);
        ~ThrottleValve();
        void set_position(uint16_t new_position);
        int get_sensor();
        int get_position();
        int get_delta_home();
        int get_tension(uint8_t channel);
        void command(uint8_t action);
        int read(uint8_t _register);
};