//
// Created by manfer on 31/10/19.
//

#ifndef PROTOCOLO_SERVIDORPROXY_H
#define PROTOCOLO_SERVIDORPROXY_H


#include "Protocolo.h"

class ServidorProxy {
    Protocolo protocolo;
public:
    ServidorProxy(const std::string& host, const std::string& servicio);
    void ejecutarComando(const std::string& comando);
    void elegirPartida(const std::string& nombre);
    void crearPartida(const std::string& nombre, const int& cantJugadores);
};


#endif //PROTOCOLO_SERVIDORPROXY_H
