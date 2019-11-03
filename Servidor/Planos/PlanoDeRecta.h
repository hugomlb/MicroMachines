#ifndef _PLANODERECTA_H_
#define _PLANODERECTA_H_

#include "PlanoDeSuelo.h"
#include "../Mapa.h"

class PlanoDeRecta: public PlanoDeSuelo {
  private:
    std::string material;
    int posicionX;
    int posicionY;
    std::string tipo;
  public:
    PlanoDeRecta(const std::string& configuracion);

    void agregarSueloA(Mapa *mapa) override;

    ~PlanoDeRecta();
};


#endif
