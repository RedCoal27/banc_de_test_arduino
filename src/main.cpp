#include <Arduino.h>
#include <SoftwareSerial.h>

#include "analog/AD660.h"
#include "analog/AD7734.h"

AD660 dac(9);  // Utiliser la broche 9 pour LDAC
AD7734 adc(10);

void setup() {
    Serial.begin(9600);
    dac.begin();
    adc.configure();
}

void loop() {
    dac.writeVoltage(9);  // Ecrire 5V
    delay(1000);
    Serial.print("1: ");
    Serial.println(adc.readChannel(1),4);
    delay(1000);
    dac.writeVoltage(2.301);  // Ecrire 5V
    delay(1000);
    Serial.print("2: ");
    Serial.println(adc.readChannel(1),4);
    delay(1000);
}