#pragma once
#include <Arduino.h>
#include "mcp.h"
#include <DO/DO.h>
#include <DI/DI.h>
#include <analog/AD660.h>
#include <analog/AD7734.h>


class cmd {
    public:
        DO _DO; // Classe qui gère tous les ports de sortie
        DI _DI; // Classe qui gère tous les ports d'entrée
        AD660* _AO; // Classe qui gère tous les ports de sortie analogique
        AD7734* _AI; // Classe qui gère tous les ports d'entrée analogique
        cmd();
        void begin();
        void Command();
};