#ifndef _PARTIDA_H_
#define _PARTIDA_H_

#include <vector>
#include "Box2D/Box2D.h"
#include "Pista.h"
#include "../Planos/PlanoDePista.h"
#include "../Planos/PlanoDeCarro.h"
#include "../Hilo.h"
#include "../Comunicacion/ClienteProxy.h"
#include "../Comunicacion/Estados/EstadoPartida.h"
#include "HashProtegidoClientes.h"

class Partida: public Hilo {
private:
    Pista pista;
    HashProtegidoClientes clientes;
    std::unique_ptr<EstadoPartida> estado;
    std::vector<std::string> suelos;

public:

    Partida(int cantJugadores, PlanoDePista *pista);

    void run() override;

    std::vector<std::string>& obtenerMapa();

    Carro * agregarCliente(PlanoDeCarro *planoDeCarro, ClienteProxy &cliente);

    void eliminarCliente(ClienteProxy& cliente);

    bool estaMuerto();

    void cerrar();

    void crearPista(PlanoDePista *planoDePista);

    ~Partida();

    void enviarMensajesInicio();

    bool estaEnJuego();
};

#endif
