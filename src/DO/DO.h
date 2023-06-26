/**
 * @file DO.h
 * @brief Header file for the DO class that controls digital outputs.
 * 
 * This file declares the DO class, which is responsible for controlling digital outputs such as solenoid valves and water level sensors.
 * It includes the mcp.h and DB25.h header files, which are used for communication with the MCP23017 I/O expander and the DB25 connector respectively.
 * The DO class has methods to open and close different electrovalves.
 * 
 */
#pragma once
#include <Arduino.h>
#include "mcp.h"
#include "DO/DB25.h"

#define Address_MCP0 0x24
#define Address_MCP1 0x25


class DO {
    private:
        mcp mcp0;
        mcp mcp1;
        void writePin(byte pin, byte value);
        void FourWayDouble(byte pin_actif, byte pin_inactif); // retire la nécéssité d'avoir un inverseur pour les 4way valve
    public:
        DO();
        void OpenSV();
        void CloseSV();
        void OpenWL1();
        void CloseWL1();
        void OpenWL2();
        void CloseWL2();
        void OpenWL3();
        void CloseWL3();

};
