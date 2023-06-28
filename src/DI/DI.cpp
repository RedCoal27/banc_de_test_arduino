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
    mcp2.begin();
    mcp3.begin();
    mcp2.setupPortA(0,0xFF,0xFF);
    mcp2.setupPortB(0,0xFF,0xFF);
    mcp3.setupPortA(0,0xFF,0xFF);
    mcp3.setupPortB(0,0xFF,0xFF);
}

