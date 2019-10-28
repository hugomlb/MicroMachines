#include "Asfalto.h"
#include "Interactuable.h"
#include <iostream>

Asfalto::Asfalto() {
  coeficienteDeRozamiento = 0.3f;
  id = "Asfalto";
}

std::string Asfalto::darId() {
  return id;
}

void Asfalto::interactuar(Carro* unCarro) {
  printf("Sobre Asfalto\n");
  unCarro -> aplicarFriccion(coeficienteDeRozamiento);
}

Asfalto::~Asfalto() {
}