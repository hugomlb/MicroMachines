//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_CREARPARTIDA_H
#define SERVIDOR_CREARPARTIDA_H


#include <map>
#include "Comando.h"
#include "../../Partida/Partida.h"
#include "../../ConfiguracionServidor.h"
#include "../../Partida/HashProtegido.h"

class CrearPartida: public Comando {
    HashProtegido& partidas;
    ConfiguracionServidor& mapasYAutos;
public:
    CrearPartida(HashProtegido &partidas,
                 ConfiguracionServidor &mapasYAutos);

    void ejecutar(ClienteProxy &cliente) override;
};


#endif //SERVIDOR_CREARPARTIDA_H
