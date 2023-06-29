/**
 * @file DO.h
 * @brief Header file for the DO class that controls digital outputs.
 * 
 * This file declares the DO class, which is responsible for controlling digital outputs for electronic valves and pump.
 * It includes the mcp.h and DB_Output.h header files, which are used for communication with the MCP23017 I/O expander and the DB25/DB15 connector respectively.
 * The DO class has methods to open and close different electrovalves.
 * 
 */
#pragma once
#include <Arduino.h>
#include "mcp.h"
#include "DO/DB_Output.h"

#define Address_MCP0 0x24
#define Address_MCP1 0x25


class DO {
    private:
        mcp mcp0;
        mcp mcp1;
        void writePin(uint8_t pin, uint8_t value);
        void FourWayDouble(uint8_t pin_actif, uint8_t pin_inactif); // retire la nécéssité d'avoir un inverseur pour les 4way valve
    public:
        DO();
        void begin();
        void Command(uint8_t action);
};
