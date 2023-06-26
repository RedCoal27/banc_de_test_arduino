#pragma once
#include <Arduino.h>
#include "mcp.h"

/**
 * @brief This file defines the pinout of a DB25 connector using two MCP23017 chips.
 * 
 * The pins are defined using binary values (B0, B1, etc.) and are mapped to their respective
 * MCP chip and pin number. The pins are also given a name for easier reference in the code.
 * 
 * @note This file requires the "mcp.h" library to be included.
 */


// pinout MCP23017 -> DB25 connector, | 16 is for MCP1 (second chip)

#define DB25_1 B0   //MCF1 (MCP0)
#define DB25_2 B1   //MCF2 (MCP0)
#define DB25_3 B2   //Nupro_Final (MCP0)
#define DB25_4 B3   //Nupro_Vent (MCP0)
#define DB25_5 B4   //GV_PVD (MCP0)
#define DB25_6 B6   //GV_CVD (MCP0)


#define DB25_7 (B0 | 16)   //SV Open (MCP1)
#define DB25_8 (B2 | 16)   //WL3 UP (MCP1)
#define DB25_9 (B4 | 16)   //WL2 UP (MCP1)
#define DB25_10 (B6 | 16)  //WL1 UP (MCP1)

#define DB25_11 A0  //not used for now (MCP0)
#define DB25_12 A2  //not used for now (MCP0)

#define DB25_14 A4  //Iso_ch (MCP0)
#define DB25_15 A5  //Iso_Turbo (MCP0)
#define DB25_16 A6  //Iso_RGA_ch (MCP0)
#define DB25_17 A7  //Iso_RGA_pompe (MCP0)


#define DB25_18 B5 //not used for now (MCP0)
#define DB25_19 B7 //not used for now (MCP0)

#define DB25_20 (B1 | 16)  //SV Close (MCP1)
#define DB25_21 (B3 | 16)  //WL3 DOWN (MCP1)
#define DB25_22 (B5 | 16)  //WL2 DOWN (MCP1)
#define DB25_23 (B7 | 16)  //WL1 DOWN (MCP1)



#define MCF1 DB25_1         //pin MCP0 B0
#define MCF2 DB25_2         //pin MCP0 B1
#define Nupro_Final DB25_3  //pin MCP0 B2
#define Nupro_Vent DB25_4   //pin MCP0 B3

#define GV_PVD DB25_5   //pin MCP0 B4
#define GV_CVD DB25_6   //pin MCP0 B6

#define SV_Open DB25_7   //pin MCP1 B0
#define WL3_Up DB25_8    //pin MCP1 B2
#define WL2_Up DB25_9    //pin MCP1 B4
#define WL1_Up DB25_10   //pin MCP1 B6

#define Iso_ch DB25_14          //pin MCP0 A4
#define Iso_Turbo DB25_15       //pin MCP0 A5
#define Iso_RGA_ch DB25_16      //pin MCP0 A6
#define Iso_RGA_pompe DB25_17   //pin MCP0 A7

#define SV_Close DB25_20 //pin MCP1 B1
#define WL3_Down DB25_21 //pin MCP1 B3
#define WL2_Down DB25_22 //pin MCP1 B5
#define WL1_Down DB25_23 //pin MCP1 B7