#pragma once
#include <Arduino.h>
#include "mcp.h"

// pinout MCP23017 -> DB25 connector, | 16 is for MCP1 (second chip)

#define DB25_1 B7   //MCF1 (MCP0)
#define DB25_2 B6   //MCF2 (MCP0)
#define DB25_3 B5   //Nupro_Final (MCP0)
#define DB25_4 B4   //Nupro_Vent (MCP0)
#define DB25_5 B3   //GV_PVD (MCP0)
#define DB25_6 B1   //GV_CVD (MCP0)


#define DB25_7 (B7 | 16)   //SV Open (MCP1)
#define DB25_8 (B5 | 16)   //WL3 UP (MCP1)
#define DB25_9 (B3 | 16)   //WL2 UP (MCP1)
#define DB25_10 (B1 | 16)  //WL1 UP (MCP1)

#define DB25_11 A5  //not used for now (MCP0)
#define DB25_12 A4  //not used for now (MCP0)

#define DB25_14 A3  //Iso_ch (MCP0)
#define DB25_15 A2  //Iso_Turbo (MCP0)
#define DB25_16 A1  //Iso_RGA_ch (MCP0)
#define DB25_17 A0  //Iso_RGA_pompe (MCP0)


#define DB25_18 B2 //not used for now (MCP0)
#define DB25_19 B0 //not used for now (MCP0)

#define DB25_20 (B6 | 16)  //SV Close (MCP1)
#define DB25_21 (B4 | 16)  //WL3 DOWN (MCP1)
#define DB25_22 (B2 | 16)  //WL2 DOWN (MCP1)
#define DB25_23 (B0 | 16)  //WL1 DOWN (MCP1)



#define MCF1 DB25_1         //pin MCP0 B7
#define MCF2 DB25_2         //pin MCP0 B6
#define Nupro_Final DB25_3  //pin MCP0 B5
#define Nupro_Vent DB25_4   //pin MCP0 B4

#define GV_PVD DB25_5   //pin MCP0 B3
#define GV_CVD DB25_6   //pin MCP0 B1

#define SV_Open DB25_7   //pin MCP1 B7
#define WL3_UP DB25_8    //pin MCP1 B5
#define WL2_UP DB25_9    //pin MCP1 B3
#define WL1_UP DB25_10   //pin MCP1 B1

#define Iso_ch DB25_14          //pin MCP0 A3
#define Iso_Turbo DB25_15       //pin MCP0 A2
#define Iso_RGA_ch DB25_16      //pin MCP0 A1
#define Iso_RGA_pompe DB25_17   //pin MCP0 A

#define SV_Close DB25_20 //pin MCP1 B2
#define WL3_DOWN DB25_21 //pin MCP1 B0
#define WL2_DOWN DB25_22 //pin MCP1 B2
#define WL1_DOWN DB25_23 //pin MCP1 B0