#include "Pista.h"
#include "../Acciones/GiroAIzquierda.h"

#define LONGITUD_DE_PISTA "4"

Material *Pista::darMaterial(const std::string& materialPedido) {
    if (materialPedido == "Asfalto") {
        return &asfalto;
    } else if (materialPedido == "Pasto"){
        return  &pasto;
    } else {
        return &limiteDePista;
    }
}

Pista::~Pista() {
}

void Pista::agregarRecta(std::string &material, float32 x, float32 y,
                         float32 angulo, int numeroDeSuelo) {
    if (material == "Asfalto") {
        BloquesDeasfalto.emplace(std::pair<int, std::unique_ptr<Suelo>>(numeroDeSuelo, new Recta(&mundoBox2D, darMaterial(material), x, y, angulo, numeroDeSuelo) ));
    } else {
        rectas.emplace_back(&mundoBox2D, darMaterial(material), x, y, angulo, numeroDeSuelo);
    }
}

void Pista::agregarCurva(float32 x, float32 y, float32 angulo, int numeroDeSuelo) {
    BloquesDeasfalto.emplace(std::pair<int, Suelo*>(numeroDeSuelo, new Curva(&mundoBox2D, &asfalto, &pasto, x, y, angulo, numeroDeSuelo)));
}

void Pista::simular() {
    float32 timeStep = 1.0f / 60.0f;
    int32 velocidadDeIteraciones = 6;
    int32 positionIterations = 2;
    mundoBox2D.simular(timeStep, velocidadDeIteraciones, positionIterations);
    mundoBox2D.actualizar();
    std::list<Carro>::iterator itCarros;
    for (itCarros = carros.begin(); itCarros != carros.end(); itCarros++) {
        itCarros -> imprimirPosicion();
        itCarros -> actualizar();
    }
}

void Pista::empaquetarCarro(std::vector<std::string> *destino) {
    std::list<Carro>::iterator itCarros;
    for (itCarros = carros.begin(); itCarros != carros.end(); itCarros++) {
        itCarros -> empaquetar(destino);
    }
}

void Pista::empaquetarSuelos(std::vector<std::string> *destino) {
    std::list<Recta>::iterator itRectas;
    destino -> emplace_back(LONGITUD_DE_PISTA);
    std::map<int, std::unique_ptr<Suelo>>::iterator itRectasDeAsfalto;
    for (itRectasDeAsfalto = BloquesDeasfalto.begin(); itRectasDeAsfalto != BloquesDeasfalto.end(); itRectasDeAsfalto++) {
        (itRectasDeAsfalto) -> second -> empaquetar(destino);
    }
    for (itRectas = rectas.begin(); itRectas != rectas.end(); itRectas++) {
        itRectas -> empaquetar(destino);
    }
}

Carro *Pista::crearCarro(int velocidad, float32 anguloEnRadianes, int agarre) {
    carros.emplace_back(&mundoBox2D, velocidad, anguloEnRadianes, agarre, 0.0f, 0.0f, carros.size());
    return &carros.back();
}

int Pista::cantidadDeCarros() {
    return carros.size();
}