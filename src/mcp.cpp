#include "mcp.h"


mcp::mcp(uint8_t chipAddr) {
    _chipAddr = chipAddr;
}

void mcp::begin() {
    Wire.begin();
}

void mcp::setupPortA(uint8_t polarity, uint8_t pullup, uint8_t dir) {
    mcu_write(GPPUA, pullup);
    mcu_write(IODIRA, dir);
    mcu_write(IPOLA, polarity);
}

void mcp::setupPortB(uint8_t polarity, uint8_t pullup, uint8_t dir) {
    mcu_write(GPPUB, pullup);
    mcu_write(IODIRB, dir);
    mcu_write(IPOLB, polarity);
}

void mcp::mcu_write(int registre, int value){
    Wire.beginTransmission(_chipAddr);
    Wire.write(registre);
    Wire.write(value);
    Wire.endTransmission();
}

byte mcp::readGPIO(byte port) {
    byte pin;
    Wire.beginTransmission(_chipAddr);
    Wire.write(port);
    Wire.endTransmission();
    delay(10);
    Wire.requestFrom(_chipAddr,1);
    if(Wire.available()){
        pin = Wire.read();
    }
    return pin;
}

void mcp::writeGPIO(byte port, byte value) {
    mcu_write(port, value);
}



void mcp::writePin(uint8_t pin, bool value) {
    //on s'assure que le pin est entre 0 et 15 (on retire l'information du mcp)
    pin = pin % 16;
    uint8_t port;
    
    //si le 4e bit est à 1, on est sur le port B
    if(pin & 8) {
        port = GPIOA;
    } else {
        port = GPIOB;
        pin -= 8;
    }

    byte current = readGPIO(port);
    if(value) {
        current |= (1 << pin);
    } else {
        current &= ~(1 << pin);
    }

    writeGPIO(port, current);
}

bool mcp::readPin(uint8_t pin) {
    pin = pin % 16;
    uint8_t port;
    //si le 4e bit est à 1, on est sur le port B
    if(pin & 8) {
        port = GPIOA;
    } else {
        port = GPIOB;
        pin -= 8;
    }

    byte current = readGPIO(port);
    return (current >> pin) & 1;
}
