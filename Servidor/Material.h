#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <iostream>
#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include "Carro.h"

class Material {
  protected:
    float32 coeficienteDeRozamiento;
  public:
    virtual void interactuar(Carro* unCarro) = 0;
};


#endif
