#include "RS485/jauge.h"

Jauge::Jauge(SoftwareSerial* _RS485){
    Serial_RS485 = _RS485;


}

String Jauge::query(uint8_t address){
    String value = "#";
    if(address < 10){
        value += "0";
    }
    value += String(address) + ":00";
    return value;
}

String Jauge::send_command(uint8_t address, String command){
    Serial_RS485->println(query(address) + command);
    if(!address)
        return "";
        
    uint16_t x = 0;
    while(!Serial_RS485->available() && x<1000){
        x++;
        delay(0.01);
    }
    if(x<1000){
        String message = Serial_RS485->readStringUntil('\n');
        return message.substring(message.indexOf(' ') + 1); 
    }
    return "error";
}