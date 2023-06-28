
#pragma once
#include <Arduino.h>
#include "mcp.h"
#include "DI/DB_Input.h"

#define Address_MCP2 0x20
#define Address_MCP3 0x21


class DI {
    private:
        mcp mcp2;
        mcp mcp3;
    public:
        DI();
        void interlock();
        void Command(char action);
};