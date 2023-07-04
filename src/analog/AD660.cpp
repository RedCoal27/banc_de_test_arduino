#include "AD660.h"
#include <Arduino.h>

AD660::AD660(uint8_t ldacPin) : _ldacPin(ldacPin) {
}

void AD660::begin() {
    SPI.begin();
    pinMode(_ldacPin, OUTPUT);
    digitalWrite(_ldacPin, LOW);
}

void AD660::sendData(byte msb, byte lsb) {
    SPI.beginTransaction(SPISettings(100000, MSBFIRST, SPI_MODE0));
    SPI.transfer(msb);
    SPI.transfer(lsb);
    digitalWrite(_ldacPin, HIGH);
    delay(0.5);
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
