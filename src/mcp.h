/**
 * @file mcp.h
 * @brief Library for controlling MCP23017 I/O expander chip.
 * 
 * This library provides an interface for controlling the MCP23017 I/O expander chip using the Arduino framework.
 * It defines the MCP class, which allows the user to configure and control the chip's pins and ports.
 * 
 * @note This library requires the Arduino.h and Wire.h libraries to be included.
 * 
 * @author Maillet Alexandre
 * @date 26/06/2023
 */
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


#define MCP_A0 0
#define MCP_A1 1
#define MCP_A2 2
#define MCP_A3 3
#define MCP_A4 4
#define MCP_A5 5
#define MCP_A6 6
#define MCP_A7 7
#define MCP_B0 8
#define MCP_B1 9
#define MCP_B2 10
#define MCP_B3 11
#define MCP_B4 12
#define MCP_B5 13
#define MCP_B6 14
#define MCP_B7 15



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
