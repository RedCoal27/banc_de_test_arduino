#include "throttle_valve.h"

ThrottleValve::ThrottleValve(uint8_t chipAddr){
    _chipAddr = chipAddr;
}

ThrottleValve::~ThrottleValve(){
}

void ThrottleValve::set_position(uint16_t new_position){
    Wire.beginTransmission(_chipAddr);
    Wire.write((uint8_t)(new_position >> 8 & 0xFF));
    Wire.write((uint8_t)(new_position & 0xFF)); 
    Wire.endTransmission();
}

int ThrottleValve::read(uint8_t _register){
    int value = 0;
    Wire.beginTransmission(_chipAddr);
    Wire.write(_register);
    Wire.endTransmission();
    Wire.beginTransmission(_chipAddr);
    Wire.requestFrom(_chipAddr, (uint8_t)2);
    value = Wire.read() << 8;
    value |= Wire.read(); 
    Wire.endTransmission();
    return value;
}


int ThrottleValve::get_position(){
    return read(POSITION);
}

int ThrottleValve::get_sensor(){
    return read(SENSORS);
}

void ThrottleValve::command(uint8_t action){
    switch (action)
    {
    case 1:{
        byte buffer[2]; // tableau pour stocker les 2 octets
        Serial.readBytes(buffer, 2); // lire 2 octets de la liaison série dans le tableau
        uint16_t new_position = *(uint16_t*)buffer; // utiliser un pointeur pour interpréter les octets comme un uint8_t
        Serial.println(new_position);
        set_position(new_position);
        break;
    }
    case 2:{
        int pos = get_position();
        Serial.write(pos>>8);
        Serial.write(pos);
        break;
    }
    case 3:{
        Serial.write(get_sensor());
        break;
    }
    }
}