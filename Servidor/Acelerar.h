#ifndef _ACELERAR_H_
#define _ACELERAR_H_

#include "Accion.h"

class Acelerar: public Accion {
  public:
    void ejecutar(b2Body* body, float32 velocidadMax);
};


#endif