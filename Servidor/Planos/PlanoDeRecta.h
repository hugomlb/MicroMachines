#ifndef _PLANODERECTA_H_
#define _PLANODERECTA_H_

#include "PlanoDeSuelo.h"
#include "../Partida/Mapa.h"

class PlanoDeRecta: public PlanoDeSuelo {
private:
    std::string material;
    int posicionX;
    int posicionY;
    std::string tipo;

    float32 obtenerAngulo();
public:
    PlanoDeRecta(const std::string& configuracion);

    void agregarSueloA(Mapa *mapa) override;

    ~PlanoDeRecta();
};


#endif
