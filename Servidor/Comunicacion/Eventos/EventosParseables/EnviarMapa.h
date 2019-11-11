//
// Created by manfer on 10/11/19.
//

#ifndef SERVIDOR_ENVIARMAPA_H
#define SERVIDOR_ENVIARMAPA_H


#include "EventosParseables.h"
#include "../../../Partida/Pista.h"

class EnviarMapa: public EventosParseables {
    Pista& pista;
public:
    explicit EnviarMapa(Pista& pista);

    std::string obtenerParseado() override;
};


#endif //SERVIDOR_ENVIARMAPA_H