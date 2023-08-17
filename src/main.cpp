#include <Arduino.h>


#include <cmd.h>

#include "Arduino_I2C/throttle_valve.h"

cmd _CMD; //classe commande

// ThrottleValve test(ADDRESS_THROTTLE);

// //fonction interuption
// void interlock(){
//     //desactivation global interuption
//     noInterrupts();
//     _CMD._DI.interlock();
//     //activation global interuption
//     interrupts();
// }


void setup() {
    Serial.begin(115200);
    Serial.setTimeout(100);
    Wire.begin();
    // _CMD.begin();
    delay(3000);
}

void loop() {
    // wait for serial data
    while(Serial.available() <= 1);
    _CMD.command();//execute received command
    Serial.flush();


    // Serial.println(String("Position:")+test.get_position());
    // Serial.println(String("Sensors:")+test.get_sensor());
    // test.set_position(0);
    // for(int i=0;i<35;i++){
    //     Serial.println(String("Position:")+test.get_position());
    //     Serial.println(String("Sensors:")+test.get_sensor());
    //     delay(100);
    // }
    // test.set_position(1000);
    // for(int i=0;i<35;i++){
    //     Serial.println(String("Position:")+test.get_position());
    //     Serial.println(String("Sensors:")+test.get_sensor());
    //     delay(100);
    // }
}

