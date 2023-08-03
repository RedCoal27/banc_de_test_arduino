#include "AD660.h"
#include <Arduino.h>

AD660::AD660(uint8_t ldacPin) : _ldacPin(ldacPin) {
}

void AD660::begin() {
    SPI.begin();
    pinMode(_ldacPin, OUTPUT);
    digitalWrite(_ldacPin, LOW);
    writeVoltage(0);
}

void AD660::sendData(byte msb, byte lsb) {
    digitalWrite(_ldacPin, HIGH);
    SPI.beginTransaction(SPISettings(200000, MSBFIRST, SPI_MODE0));
    SPI.transfer(msb);
    SPI.transfer(lsb);
    SPI.endTransaction();
    digitalWrite(_ldacPin, LOW);
}

byte AD660::voltageToMSB(float voltage) {
    uint16_t value = voltage * (65535 / 10);
    return (value >> 8);
}

byte AD660::voltageToLSB(float voltage) {
    uint16_t value = voltage * (65535 / 10);
    return value;
}

void AD660::writeVoltage(float voltage) {
    sendData(voltageToMSB(voltage), voltageToLSB(voltage));
}


void AD660::command() {
    byte buffer[4]; // tableau pour stocker les 4 octets
    Serial.readBytes(buffer, 4); // lire 4 octets de la liaison série dans le tableau

    float tension = *(float*)buffer; // utiliser un pointeur pour interpréter les octets comme un float

    writeVoltage(tension);
    
}