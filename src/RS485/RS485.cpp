#include "RS485/RS485.h"

RS485::RS485():Serial_RS485(RX_PIN, TX_PIN),_Jauge1(&Serial_RS485,Address_Jauge1){
    Serial_RS485.begin(38400);
    _Jauge1.setup();
}



void RS485::read_pressure(){
    Serial.println("test");
    _Jauge1.read_pressure();
}