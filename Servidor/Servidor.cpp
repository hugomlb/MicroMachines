#include "Servidor.h"
#include "Partida/Partida.h"
#include "Comunicacion/ClienteProxy.h"
#include "Comunicacion/Sockets/SocketPeerException.h"
#include "Comunicacion/Sockets/SocketPassiveException.h"
#include <map>
#include <chrono>
#include <string>


Servidor::Servidor(const std::string& servicio):
socketPasivo(servicio),
continuar(true),
enJuego(partidas),
enMenu(partidas, configuracion){
    //Partida hardcodeada para probar
    partidas.ubicar("prueba", new Partida(1, configuracion.darPlanoDePista("Prueba 1")));
    partidas.obtener("prueba") -> start();
}

Servidor::~Servidor() {
}

void Servidor::run() {
   while (continuar){
        try{
            SocketAmigo socketCliente = socketPasivo.aceptarCliente();
            clientes.emplace_back(new HiloCliente(socketCliente, enMenu, enJuego));
            clientes.back()->start();
            cerrar_clientes_desconectados();
            cerrar_partidas_terminadas();
        }catch (SocketPassiveException &e){
            break;
        }
    }
    //Mato a los clientes
    for (auto& cliente : clientes){
        cliente->desconectar();
        cliente->join();
    }
    //Mato a las partidas
    for (auto& partida : partidas.obtenerClaves()) {
        partidas.obtener(partida)->cerrar();
        partidas.obtener(partida)->join();
    }
}


HashProtegido & Servidor::obtenerPartidas() {
    return partidas;
}

void Servidor::cerrar_clientes_desconectados() {
    size_t i = 0;
    while(i < clientes.size()) {
        if (clientes[i]->estaMuerto()) {
            clientes[i]->join();
            clientes.erase(clientes.begin() + i);
        } else {
            i++;
        }
    }

}

void Servidor::cerrar_partidas_terminadas() {
    for (auto& partida : partidas.obtenerClaves()){
        if (partidas.obtener(partida)->estaMuerto()){
            partidas.eliminar(partida);
        }
    }
}

void Servidor::apagar() {
    continuar = false;
    socketPasivo.cerrar();
}
