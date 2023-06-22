#include <Arduino.h>
#include <mcp.h>

#include <DO/DO.h>

mcp mcp0(0x20);//test input temporaire 

DO _DO; // Classe qui gère tous les ports de sortie


void setup() {
    Serial.begin(9600);
    mcp0.setupPortA(0x00, 0x0f, 0xff);
    mcp0.setupPortB(0x00, 0x0f, 0xff);
}

byte test = 0;
void loop() {
    byte pinA = mcp0.readGPIO(GPIOA);
    Serial.println(pinA, BIN);

    _DO.OpenSV();
    delay(2000);
    _DO.CloseSV();
    delay(2000);
    
}
