#include <Arduino.h>


#include <cmd.h>

#include "analog/AD7734.h"

cmd _CMD; //classe commande

// //fonction interuption
// void interlock(){
//     //desactivation global interuption
//     noInterrupts();
//     _CMD._DI.interlock();
//     //activation global interuption
//     interrupts();
// }


// void setup() {
//     Serial.begin(9600);
//     Wire.begin();
//     _CMD.begin();
// }

// void loop() {
//     //wait for serial data
//     while(Serial.available() == 0);
//     _CMD.Command();//execute received command
//     Serial.flush();
// }


AD7734 ad7734;

void setup() {
    Serial.begin(9600);
    ad7734.configure();
}

void loop() {
    for (int channel = 0; channel < 4; channel++) {
        Serial.print("Channel ");
        Serial.print(channel);
        Serial.print(": ");
        Serial.println(ad7734.readChannel(channel),4);
    }
    delay(1000);
}