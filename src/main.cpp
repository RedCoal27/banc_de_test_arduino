#include <Arduino.h>
#include <mcp.h>

mcp mcp1(0x20);
mcp mcp2(0x21);

void setup() {
    mcp1.begin();
    mcp1.setupPortA(0x00, 0x0f, 0xff);
    mcp1.setupPortB(0x00, 0x0f, 0xff);
    
    mcp2.begin();
    mcp2.setupPortA(0x00, 0x00, 0x00);
    mcp2.setupPortB(0x00, 0x00, 0x00);
}

void loop() {
    byte pinA = mcp1.readGPIO(GPIOA);
    byte pinB = mcp1.readGPIO(GPIOB);
    Serial.println(pinA, BIN);
    Serial.println(pinB, BIN);
    
    mcp2.writeGPIO(GPIOA, !pinA);
    mcp2.writeGPIO(GPIOB, !pinB);
    delay(3000);
}
