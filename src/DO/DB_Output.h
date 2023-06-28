#pragma once
#include <Arduino.h>
#include "mcp.h"

/**
 * @brief Ce fichier définit le brochage d'un connecteur DB25 à l'aide de deux puces MCP23017.
 * 
 * Les broches sont définies à l'aide de valeurs binaires (B0, B1, etc.) et sont mappées sur leur numéro de broche
 * respectif de la puce MCP. Les broches sont également nommées pour une référence plus facile dans le code.
 * 
 * @note Ce fichier nécessite l'inclusion de la bibliothèque "mcp.h".
 */


// brochage MCP23017 -> connecteur DB25, | 16 est pour MCP1 (deuxième puce)

#define DB25_1 (MCP_B3 | 16)   //MCF1 (MCP1)
#define DB25_2 (MCP_B2 | 16)   //MCF2 (MCP1)
#define DB25_3 (MCP_B1 | 16)   //Nupro_Final (MCP1)
#define DB25_4 (MCP_B0 | 16)   //Nupro_Vent (MCP1)
#define DB25_5 MCP_A3   //GV_PVD (MCP0)
#define DB25_6 MCP_A1   //GV_CVD (MCP0)


#define DB25_7 MCP_B7   //SV Open (MCP0)
#define DB25_8 MCP_B5   //WL3 UP (MCP0)
#define DB25_9 MCP_B3   //WL2 UP (MCP0)
#define DB25_10 MCP_B1  //WL1 UP (MCP0)

#define DB25_11 MCP_A7  //pas utilisé pour le moment (MCP0)
#define DB25_12 MCP_A5  //pas utilisé pour le moment (MCP0)

#define DB25_14 (MCP_B7 | 16)  //Iso_ch (MCP1)
#define DB25_15 (MCP_B6 | 16)  //Iso_Turbo (MCP1)
#define DB25_16 (MCP_B5 | 16)  //Iso_RGA_ch (MCP1)
#define DB25_17 (MCP_B4 | 16)  //Iso_RGA_pompe (MCP1)


#define DB25_18 MCP_A2 //pas utilisé pour le moment (MCP0)
#define DB25_19 MCP_A0 //pas utilisé pour le moment (MCP0)

#define DB25_20 MCP_B6  //SV Close (MCP0)
#define DB25_21 MCP_B4  //WL3 DOWN (MCP0)
#define DB25_22 MCP_B2  //WL2 DOWN (MCP0)
#define DB25_23 MCP_B0  //WL1 DOWN (MCP0)

#define DB25_24 MCP_A6 //pas utilisé pour le moment (MCP0)
#define DB25_25 MCP_A4 //pas utilisé pour le moment (MCP0)




// lien entre les broches et les noms des électrovannes
#define MCF1 DB25_1         //broche MCP1 B3
#define MCF2 DB25_2         //broche MCP1 B2
#define Nupro_Final DB25_3  //broche MCP1 B1
#define Nupro_Vent DB25_4   //broche MCP1 B0

#define GV_PVD DB25_5   //broche MCP0 A3
#define GV_CVD DB25_6   //broche MCP0 A1

#define SV_Open DB25_7   //broche MCP0 B7
#define WL3_Up DB25_8    //broche MCP0 B5S
#define WL2_Up DB25_9    //broche MCP0 B3
#define WL1_Up DB25_10   //broche MCP0 B1

#define Iso_ch DB25_14          //broche MCP1 B7
#define Iso_Turbo DB25_15       //broche MCP1 B6
#define Iso_RGA_ch DB25_16      //broche MCP1 B5
#define Iso_RGA_pompe DB25_17   //broche MCP1 B4

#define SV_Close DB25_20 //broche MCP0 B6
#define WL3_Down DB25_21 //broche MCP0 B4
#define WL2_Down DB25_22 //broche MCP0 B2
#define WL1_Down DB25_23 //broche MCP0 B0



//DB15
#define Turbo_RGA (MCP_A1 | 16) //DB15_2 - DB15_10
#define Turbo_Ch (MCP_A2 | 16)  //DB15_3 - DB15_11
#define DB15_4_12 (MCP_A3 | 16) //DB15_4 - DB15_12 (Non utilisé)
#define DB15_5_13 (MCP_A4 | 16) //DB15_5 - DB15_13 (Non utilisé)
#define DB15_6_14 (MCP_A5 | 16) //DB15_6 - DB15_14 (Non utilisé)
#define DB15_7_15 (MCP_A6 | 16) //DB15_7 - DB15_15 (Non utilisé)
#define DB15_8 (MCP_A7 | 16)    //DB15_8 (Ground) (Non utilisé)

#define Pump_Start (MCP_A0 | 16)//DB15_9 - DB15_1 (24V)
