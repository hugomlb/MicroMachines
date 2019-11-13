//
// Created by diego on 28/10/19.
//

#ifndef OPENGLTEST_AUTO_H
#define OPENGLTEST_AUTO_H


#include "../Sdl/Posicion.h"
#include "../Sdl/Renderizador.h"
#include "Desplazable.h"

class Auto : public Desplazable {
private:
    int etapaExplosion;
    unsigned long idExplosion;

public:
    Auto(Renderizador &renderizador, int tam);

    void mover(float posX, float posY, int angulo) override;

    void morir() override;

    void modificar(std::string &mensaje) override;

    void eliminar() override;
};


#endif //OPENGLTEST_AUTO_H
