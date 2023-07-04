#ifndef AD660_H
#define AD660_H

#include <Arduino.h>
#include <SPI.h>

class AD660 {
public:
    AD660(uint8_t ldacPin);
    void begin();
    void writeVoltage(float voltage);
private:
    uint8_t _ldacPin;
    void sendData(byte msb, byte lsb);
    byte voltageToMSB(float voltage);
    byte voltageToLSB(float voltage);
};

#endif //AD660_H
