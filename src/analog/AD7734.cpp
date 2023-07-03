#include "analog/AD7734.h"

AD7734::AD7734() {
    pinMode(CS_PIN, OUTPUT);
    SPI.setClockDivider(SPI_CLOCK_DIV32);
    SPI.begin();
}

void AD7734::configure() {
    for(int channel = 0; channel < 4; channel++){
        writeRegister(CHANNEL_SETUP_REG + channel, 0x01);
        writeRegister(CONVERSION_TIME_REG + channel, 0xFF);
        writeRegister(MODE_REG + channel, 0x82);
        delay(1000);
    }
}

float AD7734::tensionConverter(uint32_t value){
    return float(value) * 10 / 0xFFFFFF;
}

uint32_t AD7734::readAverageValue(byte channel, int sample){
    uint32_t average = 0;
    for(int i = 0; i < sample; i++){
        writeRegister(MODE_REG + channel, 0x42);
        delay(20);
        average += readRegister(CHANNEL_DATA_REG + channel, 3);
        if((readRegister(CHANNEL_STATUS + channel, 1) & 0x03) == 1){
            average += 0xFFFFFF;
        }
    }
    average /= sample;
    return average;
}

void AD7734::writeRegister(byte reg, byte value) {
    digitalWrite(CS_PIN, LOW);
    SPI.transfer(reg);
    SPI.transfer(value);
    digitalWrite(CS_PIN, HIGH);
}

uint32_t AD7734::readRegister(byte reg, byte toRead) {
    digitalWrite(CS_PIN, LOW);
    SPI.transfer(reg | 64);
    uint32_t value = 0;
    for(int i = 0; i < toRead; i++){
        value = value << 8;
        value += uint32_t(SPI.transfer(0x00));
    }
    digitalWrite(CS_PIN, HIGH);
    return value;
}


float AD7734::readChannel(byte channel){
    uint32_t data = readAverageValue(channel, 4);
    return tensionConverter(data);
}