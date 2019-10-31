#include "Recta.h"

Recta::Recta(Pista *pista, Material *unMaterial) {
  material = unMaterial;
  defCuerpo.type = b2_staticBody;
  defCuerpo.position.Set(0.0f, 4.0f); //Posicion HARDCODEADA
  cuerpo = pista -> agregarObjeto(defCuerpo);
  cuerpo -> SetUserData(this);
  b2PolygonShape cajaEstatica;
  cajaEstatica.SetAsBox(2.0f, 2.0f); //TAMANIO DE CUADRADO HARDCODEADO
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &cajaEstatica;
  fixtureDef.density = 0.0f;
  fixtureDef.friction = 0.3f;
  fixtureDef.isSensor = true;
  cuerpo -> CreateFixture(&fixtureDef);
}

Recta::~Recta() {
}

void Recta::interactuar(Carro *unCarro) {
  material -> interactuar(unCarro);
}

std::string Recta::darId() {
  return "Recta";
}

bool Recta::esValido() {
  return true;
}
