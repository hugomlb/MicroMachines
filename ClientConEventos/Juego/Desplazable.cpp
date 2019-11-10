//
// Created by diego on 9/11/19.
//

#include "Desplazable.h"

Posicion* Desplazable::getPosicion() {
    return &posicion;
}

Desplazable::Desplazable(Renderizador &renderizador, int tam)\
: posicion(0,0, tam, tam, 0), renderizador(renderizador){}
