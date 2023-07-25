#include "RS485/RS485.h"

RS485::RS485():Serial_RS485(RX_PIN, TX_PIN),_Jauge1(&Serial_RS485,Address_Jauge1),_Jauge2(&Serial_RS485,Address_Jauge2){
    Serial_RS485.begin(38400);
    Serial_RS485.setTimeout(100);
}


void RS485::setup(){
    _Jauge1.setup();
    _Jauge2.setup();
}

void RS485::read_pressure(){
    _Jauge1.read_pressure();
    delay(10);
    _Jauge2.read_pressure();
    delay(10);
}
