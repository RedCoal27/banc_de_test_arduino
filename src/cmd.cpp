#include "cmd.h"

/**
 * @brief Constructeur de l'objet cmd
 * 
 */
cmd::cmd(){
}

void cmd::begin(){
    _DO.begin();
    _DI.begin();
}

/**
 * @brief Lit une commande depuis le port série et l'exécute
 * 
 */
void cmd::Command(){
    uint8_t port = Serial.read();
    //switch case pour les ports
    while(Serial.available() == 0);
    switch (port)
    {
    case 0:
        _DO.Command(Serial.read());
        break;
    case 1:
        _DI.Command(Serial.read());
        break;
    default:
        Serial.print(0);
        break;
    }
}
