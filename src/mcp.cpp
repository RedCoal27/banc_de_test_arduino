#include "mcp.h"

/**
 * @brief Construct a new mcp object
 * 
 * @param chipAddr The address of the MCP23017 chip
 */
mcp::mcp(uint8_t chipAddr) {
    _chipAddr = chipAddr;
}

/**
 * @brief Initializes the Wire library
 * 
 */
void mcp::begin() {
    Wire.begin();
    // mcu_write(IOCON,0b00001000);
}

/**
 * @brief Configures the MCP23017 Port A
 * 
 * @param polarity The polarity of the input pins
 * @param pullup The pull-up resistor configuration
 * @param dir The direction of the pins
 */
void mcp::setupPortA(uint8_t polarity, uint8_t pullup, uint8_t dir) {
    mcu_write(GPPUA, pullup);
    mcu_write(IODIRA, dir);
    mcu_write(IPOLA, polarity);
}

/**
 * @brief Configures the MCP23017 Port B
 * 
 * @param polarity The polarity of the input pins
 * @param pullup The pull-up resistor configuration
 * @param dir The direction of the pins
 */
void mcp::setupPortB(uint8_t polarity, uint8_t pullup, uint8_t dir) {
    mcu_write(GPPUB, pullup);
    mcu_write(IODIRB, dir);
    mcu_write(IPOLB, polarity);
}

/**
 * @brief Writes a value to a MCP23017 register
 * 
 * @param registre The register to write to
 * @param value The value to write
 */
void mcp::mcu_write(uint8_t registre, uint8_t value){

    Wire.beginTransmission(_chipAddr);
    Wire.write(registre);
    Wire.write(value);
    Wire.endTransmission();
}

/**
 * @brief Reads the value of a MCP23017 GPIO port
 * 
 * @param port The port to read from
 * @return uint8_t The value of the port
 */
uint8_t mcp::readGPIO(uint8_t port) {
    uint8_t pin = 0;
    Wire.beginTransmission(_chipAddr);
    Wire.write(port);
    Wire.endTransmission();
    delay(10);
    Wire.requestFrom(_chipAddr, 1);
    if(Wire.available()){
        pin = Wire.read();
    }
    return pin;
}

/**
 * @brief Writes a value to a MCP23017 GPIO port
 * 
 * @param port The port to write to
 * @param value The value to write
 */
void mcp::writeGPIO(uint8_t port, uint8_t value) {
    mcu_write(port, value);
}

/**
 * @brief Writes a value to a MCP23017 GPIO pin
 * 
 * @param pin The pin to write to
 * @param value The value to write
 */
void mcp::writePin(uint8_t pin, bool value) {
    //on s'assure que le pin est entre 0 et 15 (on retire l'information du mcp)
    pin = pin % 16;
    uint8_t port;

    
    //si le 4e bit est à 1, on est sur le port B
    if(pin < 8) {
        port = GPIOA;
    } else {
        port = GPIOB;
        pin -= 8;
    }

    uint8_t current = readGPIO(port);
    // Serial.println(current);
    if(value) {
        current |= (1 << pin);
    } else {
        current &= ~(1 << pin);
    }
    writeGPIO(port, current);
}

/**
 * @brief Reads the value of a MCP23017 GPIO pin
 * 
 * @param pin The pin to read from
 * @return bool The value of the pin
 */
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

    uint8_t current = readGPIO(port);
    return (current >> pin) & 1;
}
