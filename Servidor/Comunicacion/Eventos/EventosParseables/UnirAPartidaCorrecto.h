//
// Created by manfer on 10/11/19.
//

#ifndef SERVIDOR_UNIRAPARTIDACORRECTO_H
#define SERVIDOR_UNIRAPARTIDACORRECTO_H


#include "EventosParseables.h"

class UnirAPartidaCorrecto: public EventosParseables {

public:
    std::string obtenerParseado() override;
};


#endif //SERVIDOR_UNIRAPARTIDACORRECTO_H