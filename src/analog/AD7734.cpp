#include "analog/AD7734.h"

AD7734::AD7734(uint8_t CS_PIN):_CS_PIN(CS_PIN){
    pinMode(_CS_PIN, OUTPUT);
    SPI.begin();
}

void AD7734::configure() {
    for(int channel = 0; channel < 4; channel++){
        writeRegister(CHANNEL_SETUP_REG + channel, 0x09);
        writeRegister(CONVERSION_TIME_REG + channel, 0xFF);
        writeRegister(MODE_REG + channel, 0x82);
        delay(50);
        writeRegister(MODE_REG + channel, 0x22);
    }
}

float AD7734::tensionConverter(uint32_t value){
    return float(value) * 10 / 0xFFFFFF;
}

uint32_t AD7734::readValue(byte channel){
    uint32_t value = readRegister(CHANNEL_DATA_REG + channel, 3);
    if((readRegister(CHANNEL_STATUS + channel, 1) & 0x03) == 1){
            value += 0xFFFFFF;
        }
    return value;
}

void AD7734::writeRegister(byte reg, byte value) {
    SPI.beginTransaction(SPISettings(100000, MSBFIRST, SPI_MODE0));
    digitalWrite(_CS_PIN, LOW);
    SPI.transfer(reg);
    SPI.transfer(value);
    digitalWrite(_CS_PIN, HIGH);
    SPI.endTransaction();
}

uint32_t AD7734::readRegister(byte reg, byte toRead) {
    SPI.beginTransaction(SPISettings(100000, MSBFIRST, SPI_MODE0));
    digitalWrite(_CS_PIN, LOW);
    SPI.transfer(reg | 64);
    uint32_t value = 0;
    for(int i = 0; i < toRead; i++){
        value = value << 8;
        value += uint8_t(SPI.transfer(0x00));
    }
    digitalWrite(_CS_PIN, HIGH);
    SPI.endTransaction();
    return value;
}


float AD7734::readChannel(byte channel){
    uint32_t data = readValue(channel);
    return tensionConverter(data);
}



void AD7734::readAllChannels(float* channel){
    for(int i=0; i<4; i++){
        channel[i] = readChannel(i);
    }
}

void AD7734::command(){
    uint8_t cmd = Serial.read();

    if(cmd < 4){
        Serial.println(readChannel(cmd),3);
    }
    if (cmd == 4){
        float channels[4];
        readAllChannels(channels);
        for(int i = 0; i < 4; i++){
            Serial.print(channels[i],3);
            Serial.print(" ");
        }
        Serial.println();
    }
}
