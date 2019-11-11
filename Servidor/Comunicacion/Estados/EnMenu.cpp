#include "EnMenu.h"
#include "../Sockets/SocketPeerException.h"
#include "../Eventos/EventosEjecutables/CrearPartida.h"
#include "../Eventos/EventosEjecutables/UnirAPartida.h"
#include "../Eventos/EventosEjecutables/ObtenerPartidas.h"
#include "../Utilidades.h"

#define MSJ_CMD_INVALIDO "ComandoInvalido"

EnMenu::EnMenu(HashProtegido &partidas, ConfiguracionServidor &config):
    partidas(partidas), mapasYAutos(config){
    //Creo comando CrearPartida y UnirseAPartida
    comandos.emplace("CrearPAR", new CrearPartida(partidas, mapasYAutos));
    comandos.emplace("PAR", new ObtenerPartidas(partidas));
    comandos.emplace("UnirPAR", new UnirAPartida(partidas, mapasYAutos));
    //ObtenerPartidas
    //ObtenerMapa
    //ObtenerAutos ?
}

void EnMenu::ejecutar(ClienteProxy &cliente) {
    std::string evento = cliente.recibir();
    std::vector<std::string> argumentos = separar(evento, ';');
    std::string eventoId = *argumentos.begin();
    if (comandos.find(eventoId) == comandos.end()){
        cliente.enviar(MSJ_CMD_INVALIDO);
    }else{
        argumentos.erase(argumentos.begin());
        comandos[eventoId]->ejecutar(cliente, argumentos);
    }
}

