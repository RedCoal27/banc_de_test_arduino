#pragma once
#include <Arduino.h>
#include "mcp.h"
#include <DO/DO.h>
#include <DI/DI.h>

class cmd {
    public:
        cmd();
        DO _DO; // Classe qui gère tous les ports de sortie
        DI _DI; // Classe qui gère tous les ports d'entrée
        void Command();
};