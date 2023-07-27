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
    for(int i=0; i < 4; i++){
        _AO[i].begin();
    }
    _AI[0].configure();
    _AI[1].configure();

    _RS485.setup();
}

/**
 * @brief Lit une commande depuis le port série et l'exécute
 * 
 */
void cmd::command(){
    uint8_t port = Serial.read();
    switch (port)
    {
    case 0: //DO
        _DO.command(Serial.read());
        break;
    case 1: //DI
        _DI.command(Serial.read());
        break;
    case 2:
    case 3:
    case 4:
    case 5: //AO
        _AO[port - 2].command();
        break;
    case 6:
    case 7: //AI
        _AI[port - 6].command();
        break;
    case 8:
        _RS485.read_pressure(Serial.read());
        break;
    default:
        Serial.print(port);
        break;
    }
}
