#include "RS485/RS485.h"

RS485::RS485():Serial_RS485(RX_PIN, TX_PIN),_Jauge(&Serial_RS485){
    Serial_RS485.begin(9600);
    Serial_RS485.setTimeout(120);
}


void RS485::setup(){
}

void RS485::read_pressure(char address){
    if(address < 100){
        String command = Serial.readStringUntil('\n');
        Serial.println(_Jauge.send_command(address, command));
    }
}
