#pragma once

#ifndef AD7734_H
#define AD7734_H

#include <Arduino.h>
#include <SPI.h>

#define CS_PIN 10
#define COMMUNICATIONS_REG 0x00
#define CHANNEL_SETUP_REG 0x28
#define CHANNEL_DATA_REG 0x08
#define CHANNEL_STATUS 0x20
#define CONVERSION_TIME_REG 0x30
#define MODE_REG 0x38
#define CHANNEL_SETUP_VALUE 0x20
#define MODE_VALUE 0x04

class AD7734 {
    public:
        AD7734();
        void configure();
        float tensionConverter(uint32_t value);
        uint32_t readAverageValue(byte channel, int sample);
        float readChannel(byte channel);
    private:
        void writeRegister(byte reg, byte value);
        uint32_t readRegister(byte reg, byte toRead);
};

#endif // AD7734_H
