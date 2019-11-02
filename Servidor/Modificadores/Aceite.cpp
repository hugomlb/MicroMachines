#include "Aceite.h"

Aceite::Aceite(Pista *pista, float32 x, float32 y) {
  b2BodyDef bodyDef;
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(x, y);
  cuerpo = pista -> agregarObjeto(&bodyDef);
  cuerpo -> SetUserData(this);
  b2PolygonShape staticBox;
  staticBox.SetAsBox(1.0f, 1.0f);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &staticBox;
  fixtureDef.density = 1.0f;
  fixtureDef.isSensor = true;
  validez = true;
  cuerpo -> CreateFixture(&fixtureDef);
}

void Aceite::interactuar(Carro *unCarro) {
  unCarro -> reducirAgarre();
  validez = false;
}

bool Aceite::esValido() {
  return validez;
}
