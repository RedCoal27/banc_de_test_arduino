#include "cmd.h"

/**
 * @brief Constructeur de l'objet cmd
 * 
 */
cmd::cmd():_DO(),_DI() {
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
        Command_DI(Serial.read());
        break;
    default:
        Serial.print(0);
        break;
    }
}
