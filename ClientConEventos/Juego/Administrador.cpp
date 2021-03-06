//
// Created by diego on 9/11/19.
//

#include <iostream>
#include "Administrador.h"
#include "Auto.h"
#include "../Excepciones/ExcepcionConPos.h"
#include "../ComandosVisualizacion/ComandoMorir.h"
#include "../ComandosVisualizacion/ComandoPosicionarExtra.h"
#include "../ComandosVisualizacion/ComandoPosicionarAuto.h"
#include "../ComandosVisualizacion/ComandoEliminar.h"
#include "../ComandosVisualizacion/ComandoGanador.h"
#include "../ComandosVisualizacion/ComandoActualizarVida.h"
#include "../ComandosVisualizacion/ComandoPodio.h"

Administrador::Administrador(Renderizador &renderizador, std::mutex& m, bool& keepTalking) : renderizador(renderizador),\
pista(renderizador), m(m), keepTalking(keepTalking), posTexto(0,renderizador.obtenerAltura()/5,\
renderizador.obtenerAncho(),renderizador.obtenerAltura()/10,0){
    comandos["morir"] = new ComandoMorir(desplazables, renderizador);
    comandos["posicionarExtra"] = new ComandoPosicionarExtra(desplazables, renderizador);
    comandos["eliminar"] = new ComandoEliminar(desplazables, renderizador);
    idTexto = "cant jugadores";
}

void Administrador::ejecutarEventos(std::vector<std::string> &eventos) {
    std::unique_lock<std::mutex> lock(m);
    while(!eventos.empty() && keepTalking){
        auto it = comandos.find(eventos[0]);
        eventos.erase(eventos.begin());
        if(it != comandos.end()){
            it->second->ejecutar(eventos);
        }
    }
}

void Administrador::actualizarJugadores(std::vector<std::string> &evento) {
    renderizador.borrarTexto(idTexto);
    renderizador.agregarTexto("Cantidad de jugadores: " + evento[0], &posTexto, idTexto, 255, 255, 255);
    evento.erase(evento.begin());
}

void Administrador::crearPista(std::vector<std::string> &planos) {
    renderizador.borrarTexto(idTexto);
    pista.crear(planos);
}

Desplazable* Administrador::crearMiAuto(std::vector<std::string> &evento) {
    evento.erase(evento.begin());
    desplazables.emplace(evento[0], new Auto(renderizador, 1, evento[0], true));
    comandos["actualizarVida"] = new ComandoActualizarVida(desplazables, renderizador, evento[0]);
    comandos["podio"] = new ComandoPodio(desplazables, renderizador, evento[0]);
    comandos["posicionarAuto"] = new ComandoPosicionarAuto(desplazables, renderizador, evento[0]);
    comandos["ganador"] = new ComandoGanador(desplazables, renderizador, keepTalking, evento[0]);
    auto it = desplazables.find(evento[0]);
    renderizador.configurarCamara(it->second->getPosicion());
    return it->second;
}

Administrador::~Administrador() {
    for(auto & comando : comandos){
        delete(comando.second);
    }
}
