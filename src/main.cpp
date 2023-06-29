#include <Arduino.h>
#include <cmd.h>

cmd _CMD; //classe commande

// //fonction interuption
// void interlock(){
//     //desactivation global interuption
//     noInterrupts();
//     _CMD._DI.interlock();
//     //activation global interuption
//     interrupts();
// }


void setup() {
    Serial.begin(9600);
    // attachInterrupt(digitalPinToInterrupt(2), interlock, RISING);
}

void loop() {
    //wait for serial data
    while(Serial.available() == 0);
    _CMD.Command();//execute received command
    Serial.flush();
}



