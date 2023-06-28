/**
 * @file DO.cpp
 * @brief Implementation of the DO class methods to control digital outputs
 * 
 */

#include "DO/DO.h"

/**
 * @brief Construct a new DO object
 * 
 * Initializes the MCP23017 chips and sets up the ports for both chips.
 * 
 */
DO::DO(): mcp0(Address_MCP0), mcp1(Address_MCP1) {
    mcp0.begin();
    mcp1.begin();
    mcp0.setupPortA(0, 0, 0);
    mcp0.setupPortB(0, 0, 0);
    mcp1.setupPortA(0, 0, 0);
    mcp1.setupPortB(0, 0, 0);
}

/**
 * @brief Write a value to a specific pin
 * 
 * @param pin The pin number to write to
 * @param value The value to write (0 or 1)
 */
void DO::writePin(byte pin, byte value) {
    if (pin < 16)
        mcp0.writeGPIO(pin, value);
    else
        mcp1.writeGPIO(pin, value);
}

/**
 * @brief Set the four-way double valve to a specific position
 * 
 * @param pin_actif The pin number to activate
 * @param pin_inactif The pin number to deactivate
 */
void DO::FourWayDouble(byte pin_actif, byte pin_inactif) {
    byte portB = mcp0.readGPIO(GPIOB);
    //mettre à 0 le pin inactif
    portB &= ~(1 << (pin_inactif%8));
    //mettre à 1 le pin actif
    portB |= (1 << (pin_actif%8));
    mcp0.writeGPIO(GPIOB, portB);
}

/**
 * @brief Open the slit valve
 * 
 * Activates the pin for opening the slit valve and deactivates the pin for closing it.
 * 
 */
void DO::OpenSV() {
    FourWayDouble(SV_Open, SV_Close);
}

/**
 * @brief Close the slit valve
 * 
 * Activates the pin for closing the slit valve and deactivates the pin for opening it.
 * 
 */
void DO::CloseSV() {
    FourWayDouble(SV_Close, SV_Open);
}

/**
 * @brief Open the first wafer lift
 * 
 * Activates the pin for lifting the first wafer and deactivates the pin for lowering it.
 * 
 */
void DO::OpenWL1() {
    FourWayDouble(WL1_Up, WL1_Down);
}

/**
 * @brief Close the first wafer lift
 * 
 * Activates the pin for lowering the first wafer and deactivates the pin for lifting it.
 * 
 */
void DO::CloseWL1() {
    FourWayDouble(WL1_Down, WL1_Up);
}

/**
 * @brief Open the second wafer lift
 * 
 * Activates the pin for lifting the second wafer and deactivates the pin for lowering it.
 * 
 */
void DO::OpenWL2() {
    FourWayDouble(WL2_Up, WL2_Down);
}

/**
 * @brief Close the second wafer lift
 * 
 * Activates the pin for lowering the second wafer and deactivates the pin for lifting it.
 * 
 */
void DO::CloseWL2() {
    FourWayDouble(WL2_Down, WL2_Up);
}

/**
 * @brief Open the third wafer lift
 * 
 * Activates the pin for lifting the third wafer and deactivates the pin for lowering it.
 * 
 */
void DO::OpenWL3() {
    FourWayDouble(WL3_Up, WL3_Down);
}

/**
 * @brief Close the third wafer lift
 * 
 * Activates the pin for lowering the third wafer and deactivates the pin for lifting it.
 * 
 */
void DO::CloseWL3() {
    FourWayDouble(WL3_Down, WL3_Up);
}
