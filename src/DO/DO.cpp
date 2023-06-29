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
 * @brief Active un pin et désactive un autre pin sur le même port B du MCP23017.
 * 
 * @param pin_on Le numéro de la broche à activer.
 * @param pin_off Le numéro de la broche à désactiver.
 * 
 * @note Cette fonction active le pin_on et désactive le pin_off sur le même port B du MCP23017.
 * @note La fonction utilise la méthode writeGPIO pour écrire sur le port B du MCP23017.
 */
void DO::FourWayDouble(byte pin_on, byte pin_off) {
    byte portB = mcp0.readGPIO(GPIOB);
    //mettre à 0 le pin inactif
    portB &= ~(1 << (pin_off%8));
    //mettre à 1 le pin actif
    portB |= (1 << (pin_on%8));
    mcp0.writeGPIO(GPIOB, portB);
}



/**
 * @brief Exécute la commande pour le port DO.
 * 
 * @param action L'action à exécuter pour le port DO.
 * 
 * @note fonction exécute la commande pour le port DO en fonction du paramètre action.
 * @note Le paramètre action est un entier qui représente le numéro de broche et l'état à définir.
 * @note La fonction utilise les méthodes writePin et FourWayDouble pour définir l'état des broches.
 * @note La fonction imprime 1 sur le port série après l'exécution de la commande
 */
void DO::Command(char action){
    //niveau bas = 1, niveau haut = 0
    bool state = action % 2;
    action = action / 2;
    switch (action)
    {
    case 1://MCF1
        writePin(Out_MCF1, state);
        break;
    case 2://MCF2
        writePin(Out_MCF2, state);
        break;
    case 3://Numpro final
        writePin(Out_Nupro_Final, state);
        break;
    case 4://Numpro Vent
        writePin(Out_Nupro_Vent, state);
        break;
    case 5://GV_PVD
        writePin(Out_GV_PVD, state);
        break;
    case 6://GV_CVD
        writePin(Out_GV_CVD, state);
        break;
    case 7://SV
        if (state)
            FourWayDouble(Out_SV_Close, Out_SV_Open);//Ouvre la SV 
        else
            FourWayDouble(Out_SV_Open, Out_SV_Close);//Ferme la SV
        break;
    case 8://WL3
        if (state)
            FourWayDouble(Out_WL3_Down, Out_WL3_Up);//Monte le WL3
        else
            FourWayDouble(Out_WL3_Up, Out_WL3_Down);//Descend le WL3
        break;
    case 9://WL2
        if (state)
            FourWayDouble(Out_WL2_Down, Out_WL2_Up);//Monte le WL2
        else
            FourWayDouble(Out_WL2_Up, Out_WL2_Down);//Descend le WL2
        break;
    case 10://WL1
        if (state)
            FourWayDouble(Out_WL1_Down, Out_WL1_Up);//Monte le WL1
        else
            FourWayDouble(Out_WL1_Up, Out_WL1_Down);//Descend le WL1
        break;
    case 14://Iso_ch
        writePin(Out_Iso_ch, state);
        break;
    case 15://Iso_Turbo
        writePin(Out_Iso_Turbo, state);
        break;
    case 16://Iso_RGA_ch
        writePin(Out_Iso_RGA_ch, state);
        break;
    case 17://Iso_RGA_pompe
        writePin(Out_Iso_RGA_pompe, state);
        break;
    }
    // Serial.print(1);
}