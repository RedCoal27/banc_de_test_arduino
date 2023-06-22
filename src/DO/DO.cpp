#include "DO/DO.h"

DO::DO(): mcp0(Address_MCP0), mcp1(Address_MCP1) {
    mcp0.begin();
    mcp1.begin();
    mcp0.setupPortA(0, 0, 0);
    mcp0.setupPortB(0, 0, 0);
    mcp1.setupPortA(0, 0, 0);
    mcp1.setupPortB(0, 0, 0);
}

void DO::writePin(byte pin, byte value) {
    if (pin < 16)
        mcp0.writeGPIO(pin, value);
    else
        mcp1.writeGPIO(pin, value);
}


// Permet d'avoir un état haut et l'autre a bas en même temps pour Waver life et slit valve (pin_actif,pin_inactif)
void DO::FourWay(byte pin_actif, byte pin_inactif) {
    byte portB = mcp1.readGPIO(GPIOB);
    //mettre à 0 le pin inactif
    portB &= ~(1 << (pin_inactif%8));
    //mettre à 1 le pin actif
    portB |= (1 << (pin_actif%8));
}


void DO::OpenSV() {
    FourWay(SV_Open, SV_Close);
}

void DO::CloseSV() {
    FourWay(SV_Close, SV_Open);
}

void DO::OpenWL1() {
    FourWay(WL1_Up, WL1_Down);
}

void DO::CloseWL1() {
    FourWay(WL1_Down, WL1_Up);
}

void DO::OpenWL2() {
    FourWay(WL2_Up, WL2_Down);
}

void DO::CloseWL2() {
    FourWay(WL2_Down, WL2_Up);
}

void DO::OpenWL3() {
    FourWay(WL3_Up, WL3_Down);
}

void DO::CloseWL3() {
    FourWay(WL3_Down, WL3_Up);
}


