#ifndef mcp_H
#define mcp_H

#include <Arduino.h>
#include <Wire.h>


#define GPIOA 0x12 // PortA reg addr
#define GPIOB 0x13 // PortB reg addr
#define IODIRA 0x00 // PortA direction reg addr
#define IODIRB 0x01 // PortB direction reg addr
#define IPOLA 0x02 // PortA polarity register
#define IPOLB 0x03 // PortB polarity register
#define GPPUA 0x0c // PortA pull-up resistor configuration
#define GPPUB 0x0d // PortB pull-up resistor configuration


#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5
#define A6 6
#define A7 7
#define B0 8
#define B1 9
#define B2 10
#define B3 11
#define B4 12
#define B5 13
#define B6 14
#define B7 15



class mcp {
    public:
        mcp(uint8_t chipAddr);
        void begin();
        void setupPortA(uint8_t polarity, uint8_t pullup, uint8_t dir);
        void setupPortB(uint8_t polarity, uint8_t pullup, uint8_t dir);
        byte readGPIO(byte port);
        void writeGPIO(byte port, byte value);
        void writePin(uint8_t pin, bool value);
        bool readPin(uint8_t pin);
    private:
        uint8_t _chipAddr;
        void mcu_write(int registre, int value);
};

#endif
