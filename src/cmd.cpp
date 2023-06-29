#include "cmd.h"

/**
 * @brief Constructeur de l'objet cmd
 * 
 */
cmd::cmd(){
}

/**
 * @brief Lit une commande depuis le port série et l'exécute
 * 
 */
void cmd::Command(){
    char port = Serial.read();
    //switch case pour les ports
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
