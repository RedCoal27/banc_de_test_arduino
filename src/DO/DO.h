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
        void FourWay(byte pin_actif, byte pin_inactif); // retire la nécéssité d'avoir un inverseur pour les 4way valve
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
