#include "Carro.h"
#include "VelocidadBase.h"
#include "../../Acciones/GiroAIzquierda.h"
#include <iostream>

Carro::Carro(MundoBox2D *pista, float32 velocidadMaxima, float32 anguloDeGiro, float32  agarre, float32 x, float32 y, int idCliente):
estadoVelocidad(velocidadMaxima), agarre(agarre) {
  this -> anguloDeGiro = anguloDeGiro;
  idConductor = "A";
  idConductor += std::to_string(idCliente);
  agregarseA(pista, x, y);
  id = "Carro";
  coeficienteDeRozamiento = 0;
}

void Carro::agregarseA(MundoBox2D *pista, float32 x, float32 y) {
    if(!vida.estoyVivo()) {
        vida.aumentarVida(100);
    }
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    cuerpo = pista -> agregarObjeto(&bodyDef);
    cuerpo -> SetUserData(this);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(0.5f, 0.5f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    cuerpo -> CreateFixture(&fixtureDef);
}

void Carro::ejecutarAccion(Accion *unaAccion) {
  unaAccion -> ejecutar(cuerpo, &estadoVelocidad, anguloDeGiro);
}

void Carro::actualizar() {
  b2Vec2 velocidad = cuerpo -> GetLinearVelocity();
  float32 factorDeFuerza = -2 * velocidad.Normalize();
  agarre.actualizar(cuerpo);
  cuerpo -> ApplyForce(coeficienteDeRozamiento * factorDeFuerza * velocidad, cuerpo -> GetWorldCenter(), true);
  visibilidad.actualizar();
  estadoVelocidad.actualizar(cuerpo);
}

void Carro::aplicarFriccion(float32 coeficienteDeRozamiento) {
  this -> coeficienteDeRozamiento = coeficienteDeRozamiento;
}

void Carro::reducirVisibilidad() {
  visibilidad.reducirVisibilidad();
}

std::string Carro::darId() {
  return id;
}

void Carro::recibirDanio(int danio) {
  vida.recibirDanio(danio);
}

void Carro::curar(int aumentoDeVida) {
  vida.aumentarVida(aumentoDeVida);
}

void Carro::reducirVelocidad(float32 factor) {
  b2Vec2 velocidad = cuerpo -> GetLinearVelocity();
  cuerpo -> SetLinearVelocity(factor * velocidad);
}

void Carro::recibirBoost() {
  estadoVelocidad.boost();
}

void Carro::imprimirPosicion() {
  b2Vec2 position = cuerpo -> GetPosition();
  float32 angle = cuerpo -> GetAngle();
  b2Vec2 velocidad = cuerpo -> GetLinearVelocity();
  printf("Nueva iteracion\n");
  std::cout << "Posicion: " << position.x << " " << position.y << " " <<  angle << std::endl;
  std::cout << "Velocidad: " << velocidad.x << " " << velocidad.y << std::endl;
}

bool Carro::esValido() {
  return vida.estoyVivo();
}

void Carro::reducirAgarre() {
  agarre.reducirAgarre();
}

void Carro::empaquetar(std::vector<std::string> *destino) {
    destino -> emplace_back(idConductor);
    empaquetarPosicion(destino);
    empaquetarAngulo(destino);
}

void Carro::actualizarPosicion(int numeroDeSuelo) {
    posicion.actualizar(numeroDeSuelo);
}

void Carro::interactuar(Carro *otroCarro) {
    otroCarro->recibirDanio(5);
}

bool Carro::operator<(const Carro &otroCarro) {
    return (this -> posicion < otroCarro.posicion);
}

std::string Carro::darIdConductor() {
    return idConductor;
}

bool Carro::termineCarrera(int cantidadDeVueltasParaTerminar) {
    return posicion.termineLaCarrera(cantidadDeVueltasParaTerminar);
}

int Carro::obtenerSueloParaRevivir() {
    return posicion.obtenerSueloParaRevivir();
}
