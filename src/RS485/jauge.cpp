#include "RS485/jauge.h"

Jauge::Jauge(SoftwareSerial* _RS485, byte address){
    Serial_RS485 = _RS485;
    _address = address;
    query = "#";
    if(address < 10){
        query += "0";
    }
    query += String(address) + ":00";

}
void Jauge::setup(){
    send_command("!C781 0");
    send_command("!S755" + String(PRESSURE_UNIT));
}

uint16_t Jauge::read_pressure(){
    // Serial.print(query + "?V752\n");
    Serial.println(send_command("?S750\n"));
    return 1;
}

String Jauge::send_command(String command){
    Serial_RS485->print(query + command);
    uint16_t x;
    while(!Serial_RS485->available() && x<1000){
        x++;
        delay(0.01);
    }
    if(x<1000)
        return(Serial_RS485->readStringUntil('\n'));
    return "err";
}