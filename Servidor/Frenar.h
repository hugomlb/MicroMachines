#ifndef _FRENAR_H_
#define _FRENAR_H_

#include "Accion.h"

class Frenar: public Accion {
  public:
    void ejecutar(b2Body* body, float32 velocidadMax);
};


#endif