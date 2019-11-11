//
// Created by diego on 9/11/19.
//

#ifndef CLIENT_DESPLAZABLE_H
#define CLIENT_DESPLAZABLE_H


#include "../Sdl/Posicion.h"
#include "../Sdl/Renderizador.h"

class Desplazable {
protected:
    Posicion posicion;
    Renderizador& renderizador;

public:
    Desplazable(Renderizador& renderizador, int tam);

    virtual void mover(float posX, float posY, int angulo) = 0;

    virtual void morir() = 0;

    virtual void modificar(std::string& mensaje) = 0;

    Posicion* getPosicion();
};


#endif //CLIENT_DESPLAZABLE_H