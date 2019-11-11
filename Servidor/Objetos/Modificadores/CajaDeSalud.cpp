#include "CajaDeSalud.h"
#define CURACION 5

CajaDeSalud::CajaDeSalud(MundoBox2D *pista, float32 x, float32 y) {
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
  id = "Caja";
}

void CajaDeSalud::interactuar(Carro *unCarro) {
  unCarro -> curar(CURACION);
  validez = false;
}

CajaDeSalud::~CajaDeSalud() {

}

bool CajaDeSalud::esValido() {
  return validez;
}