#ifndef mcp_H
#define mcp_H

#include <Arduino.h>
#include <Wire.h>

class mcp {
    public:
        mcp(uint8_t chipAddr);
        void begin();
        void setupPortA(uint8_t polarity, uint8_t pullup, uint8_t dir);
        void setupPortB(uint8_t polarity, uint8_t pullup, uint8_t dir);
        byte readGPIO(byte port);
        void writeGPIO(byte port, byte value);
    private:
        uint8_t _chipAddr;
        void mcu_write(int registre, int value);
};

#endif
