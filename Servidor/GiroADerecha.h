#ifndef _GIROADERECHA_H_
#define _GIROADERECHA_H_

#include "Accion.h"

class GiroADerecha: public Accion {
  public:
    void ejecutar(b2Body* body, EstrategiaDeVelocidad *estrategiaDeVelocidad, float32 angulo);
};


#endif
