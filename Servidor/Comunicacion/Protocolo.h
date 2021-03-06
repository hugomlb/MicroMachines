#ifndef PROTOCOLO_PROTOCOLO_H
#define PROTOCOLO_PROTOCOLO_H

#include "Sockets/SocketAmigo.h"
#include <vector>

class Protocolo {
    SocketAmigo socket;
public:
    explicit Protocolo(SocketAmigo socketAmigo);
    Protocolo(Protocolo&& otro);
    Protocolo& operator=(Protocolo&& otro);
    void enviar(const std::string &mensaje);
    std::string recibir();

    void terminarConexion();
};


#endif //PROTOCOLO_PROTOCOLO_H
