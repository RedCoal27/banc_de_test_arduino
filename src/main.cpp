#include <Arduino.h>
#include <mcp.h>

mcp mcp1(0x20);
mcp mcp2(0x27);

void setup() {
    Serial.begin(9600);
    mcp1.begin();
    mcp1.setupPortA(0x00, 0x0f, 0xff);
    mcp1.setupPortB(0x00, 0x0f, 0xff);
    
    mcp2.begin();
    mcp2.setupPortA(0x00, 0x00, 0x00);
}

byte test = 0;
void loop() {
    byte pinA = mcp1.readGPIO(GPIOA);
    Serial.println(pinA, BIN);
    mcp2.writeGPIO(GPIOA, !pinA);

    mcp2.writeGPIO(GPIOA, 0);
    delay(2000);
    mcp2.writeGPIO(GPIOA, 1);
    delay(2000);
    
}
