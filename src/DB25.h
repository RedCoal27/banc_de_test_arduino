#pragma once
#include <Arduino.h>
#include "mcp.h"

// pinout MCP23017 -> DB25 (MCP0)
#define DB25_1 B7
#define DB25_2 B6
#define DB25_3 B5
#define DB25_4 B4
#define DB25_5 B3
#define DB25_6 B1

#define DB25_18 B2
#define DB25_19 B0


#define MCF1 DB25_1 //pin MCP0 B7
#define MCF2 DB25_2 //pin MCP0 B6
#define Nupro_Final DB25_3 //pin MCP0 B5
#define Nupro_Vent DB25_4 //pin MCP0 B4
#define GV_PVD DB25_5 //pin MCP0 B3
#define GV_CVD DB25_6 //pin MCP0 B1
#define DB25_18 DB25_18 //pin MCP0 B2
#define DB25_19 DB25_19 //pin MCP0 B0
