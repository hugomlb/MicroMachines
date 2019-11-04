#ifndef _BOOST_H_
#define _BOOST_H_

#include "Modificador.h"

class Boost: public Modificador {
  public:
    Boost(Pista *pista, float32 x, float32 y);

    bool esValido();

    void interactuar(Carro* unCarro);

    ~Boost();
};


#endif