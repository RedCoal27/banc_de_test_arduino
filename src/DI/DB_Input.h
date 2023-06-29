#pragma once
#include <Arduino.h>
#include "mcp.h"

/**
 * @brief This file defines the pinout of a In_DB25 connector using two MCP23017 chips.
 * 
 * The pins are defined using binary values (B0, B1, etc.) and are mapped to their respective
 * MCP chip and pin number. The pins are also given a name for easier reference in the code.
 * 
 * @note This file requires the "mcp.h" library to be included.
 */


// pinout MCP23017 -> In_DB25 connector, | 16 is for MCP3 (second chip)
#define In_DB25_1 MCP_B0 //PVD_GV_Open
#define In_DB25_2 MCP_B1 //PVD_GV_Close
#define In_DB25_3 MCP_B2 //CVD_GV_Open
#define In_DB25_4 MCP_B3 //CVD_GV_Close

#define In_DB25_5 MCP_A7 //WL1_Down
#define In_DB25_6 MCP_A6 //WL1_Up
#define In_DB25_7 MCP_A5 //WL2_Down
#define In_DB25_8 MCP_A4 //WL2_Up
#define In_DB25_9 MCP_A3 //WL3_Down
#define In_DB25_10 MCP_A2 //WL3_Up

#define In_DB25_11 MCP_A1 //SV_Close
#define In_DB25_12 MCP_A0 //SV_Open

#define In_DB25_14 (MCP_A0 | 16) //Int_Ch_Open
#define In_DB25_15 (MCP_A1 | 16) //Int_Roughing_Pump

#define In_DB25_16 (MCP_A2 | 16) //Turbo_Pomp_Ch
#define In_DB25_17 (MCP_A3 | 16) //Prim_Pomp


// lien entre les broches et les noms des capteurs
#define In_PVD_GV_Open In_DB25_1  //broche MCP2 B0
#define In_PVD_GV_Close In_DB25_2 //broche MCP2 B1
#define In_CVD_GV_Open In_DB25_3  //broche MCP2 B2
#define In_CVD_GV_Close In_DB25_4 //broche MCP2 B3

#define In_WL1_Down In_DB25_5 //broche MCP2 A7
#define In_WL1_Up In_DB25_6   //broche MCP2 A6
#define In_WL2_Down In_DB25_7 //broche MCP2 A5
#define In_WL2_Up In_DB25_8   //broche MCP2 A4
#define In_WL3_Down In_DB25_9 //broche MCP2 A3
#define In_WL3_Up In_DB25_10  //broche MCP2 A2

#define In_SV_Close In_DB25_11    //broche MCP2 A1
#define In_SV_Open In_DB25_12     //broche MCP2 A0

#define In_Int_Ch_Open In_DB25_14         //broche MCP3 A0
#define In_Int_Roughing_Pump In_DB25_15   //broche MCP3 A1

#define In_Turbo_Pomp_Ch In_DB25_16      //broche MCP3 A2
#define In_Prim_Pomp In_DB25_17          //broche MCP3 A3



//DB9 1
#define In_DB9_1_1 (MCP_A7 | 16)   //non utilisé
#define In_DB9_1_2 (MCP_A6 | 16)   //non utilisé
#define In_DB9_1_3 (MCP_A5 | 16)   //non utilisé
#define In_DB9_1_4 (MCP_A4 | 16)   //non utilisé

#define In_Turbo_Pomp_RGA MCP_A6   //DB9_1_5
#define In_DB9_1_6 MCP_A7          //Non utilisé


//DB9 2
#define In_DB9_2_1 (MCP_B0 | 16)   //non utilisé
#define In_DB9_2_2 (MCP_B1 | 16)   //non utilisé
#define In_DB9_2_3 (MCP_B2 | 16)   //non utilisé
#define In_DB9_2_4 (MCP_B3 | 16)   //non utilisé
#define In_DB9_2_5 (MCP_B4 | 16)   //non utilisé
#define In_DB9_2_6 (MCP_B5 | 16)   //non utilisé
#define In_DB9_2_7 (MCP_B6 | 16)   //non utilisé
#define In_DB9_2_8 (MCP_B7 | 16)   //non utilisé


