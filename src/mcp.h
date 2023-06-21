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
