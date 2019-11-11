#include <sstream>
#include "PlanoDeCarro.h"

PlanoDeCarro::PlanoDeCarro(int velocidadMax, float32 anguloDeGiro, int agarre) {
    this -> velocidadMax = velocidadMax;
    this -> anguloDeGiro = (anguloDeGiro * b2_pi) / 180;
    this -> agarre = agarre;
}

Carro * PlanoDeCarro::crearCarro(Pista *pista) {
    return pista->crearCarro(velocidadMax, anguloDeGiro, agarre);
}

PlanoDeCarro::~PlanoDeCarro() {
}