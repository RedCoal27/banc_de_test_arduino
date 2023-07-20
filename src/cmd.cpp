#include "cmd.h"

/**
 * @brief Constructeur de l'objet cmd
 * 
 */
cmd::cmd(){
    //4 analog output
    _AO = new AD660[4]{
        AD660(8),
        AD660(7),
        AD660(6),
        AD660(5)
    };
    //2 analog input
    _AI = new AD7734[2]{
        AD7734(9),
        AD7734(10)
    };
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
    switch (port)
    {
    case 0: //DO
        _DO.Command(Serial.read());
        break;
    case 1: //DI
        _DI.Command(Serial.read());
        break;
    case 2:
    case 3:
    case 4:
    case 5: //AO
        _AO[port - 2].Command();
        break;
    case 6:
    case 7: //AI
        _AI[port - 6].Command();
        break;
    default:
        Serial.print(0);
        break;
    }
}
