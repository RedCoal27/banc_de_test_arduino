/**
 * @file DI.cpp
 * @brief Implementation of the DI class methods to control digital inputs
 * 
 */

#include "DI/DI.h"

/**
 * @brief Construct a new DI object
 * 
 * Initializes the MCP23017 chips and sets up the ports for both chips.
 * 
 */
DI::DI(): mcp2(Address_MCP2), mcp3(Address_MCP3) {
}

void DI::begin(){
    mcp2.setupPortA(0,0xFF,0xFF);
    mcp2.setupPortB(0,0xFF,0xFF);
    mcp3.setupPortA(0,0xFF,0xFF);
    mcp3.setupPortB(0,0xFF,0xFF);
}


/**
 * @brief Reads digital inputs from MCP23017 chips and sends them to Serial port based on the command received.
 * 
 * @param action Command to execute. 0 for reading all ports, 1 for reading MCP23017 chip 2 port A, 2 for reading MCP23017 chip 2 port B,
 * 3 for reading MCP23017 chip 3 port A, and 4 for reading MCP23017 chip 3 port B.
 */
void DI::Command(char action) {
    switch (action)
    {
    case 0:
        read_all();
        break;
    case 1:
        Serial.print(mcp2.readGPIO(GPIOA));
        break;
    case 2:
        Serial.print(mcp2.readGPIO(GPIOB));
        break;
    case 3:
        Serial.print(mcp3.readGPIO(GPIOA));
        break;
    case 4:
        Serial.print(mcp3.readGPIO(GPIOB));
        break;
    }
}



void DI::read_all(){
    // read all ports
    byte portA2 = mcp2.readGPIO(GPIOA);
    byte portB2 = mcp2.readGPIO(GPIOB);
    byte portA3 = mcp3.readGPIO(GPIOA);// interlock
    byte portB3 = mcp3.readGPIO(GPIOB);
    // send all ports
    Serial.print(portA2);
    Serial.print(portB2);
    Serial.print(portA3);
    Serial.print(portB3);
}