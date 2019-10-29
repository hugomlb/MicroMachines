//
// Created by diego on 28/10/19.
//

#ifndef OPENGLTEST_PISTA_H
#define OPENGLTEST_PISTA_H


#include <vector>
#include "../Sdl/Textura.h"
#include "../Sdl/Renderizador.h"

class Pista {

    int tamImagen;

public:
    explicit Pista(Renderizador &renderizador);

    void crearPista(Renderizador& renderizador);
};


#endif //OPENGLTEST_PISTA_H
