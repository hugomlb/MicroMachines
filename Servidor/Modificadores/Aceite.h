#ifndef _ACEITE_H_
#define _ACEITE_H_

#include "Modificador.h"

class Aceite: public Modificador {
  public:
    Aceite(Pista *pista, float32 x, float32 y);

    void interactuar(Carro* unCarro) override;

    bool esValido() override;

    ~Aceite();
};


#endif