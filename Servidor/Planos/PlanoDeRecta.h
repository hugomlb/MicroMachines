#ifndef _PLANODERECTA_H_
#define _PLANODERECTA_H_

#include "PlanoDeSuelo.h"
#include "../Partida/Pista.h"

class PlanoDeRecta: public PlanoDeSuelo {
private:
    std::string material;
    int posicionX;
    int posicionY;
    std::string tipo;

    float32 obtenerAngulo();
public:
    PlanoDeRecta(const std::string& configuracion);

    void agregarSueloA(Pista *mapa) override;

    ~PlanoDeRecta();
};


#endif
