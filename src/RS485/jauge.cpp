#include "RS485/jauge.h"

Jauge::Jauge(SoftwareSerial* Serial_RS485, byte address):_address(address){
    query = "#";
    if(address < 10){
        query += "0";
    }
    query += String(address) + ":00";

}
void Jauge::setup(){
    Serial_RS485->println("#00:01!C780 0");
    Serial_RS485->println(query + "!S755" + String(PRESSURE_UNIT));
    while(!Serial_RS485->available());
    Serial_RS485->readStringUntil('\n');
}

uint16_t Jauge::read_pressure(){
    Serial_RS485->println(query + "?V752");
    while(!Serial_RS485->available());
    Serial.println(Serial_RS485->readStringUntil('\n'));
}