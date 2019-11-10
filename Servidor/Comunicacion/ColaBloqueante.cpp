//
// Created by manfer on 10/11/19.
//

#include "ColaBloqueante.h"

void ColaBloqueante::encolar(EventosParseables *evento) {
    cola.emplace(evento);
}

void ColaBloqueante::encolar(std::shared_ptr<EventosParseables>& evento) {
    cola.push(evento);
}

std::shared_ptr<EventosParseables> ColaBloqueante::desencolar() {
    std::unique_lock<std::mutex> lock(mutex);
    while (cola.empty()){
        estaVacia.wait(lock);
    }
    std::shared_ptr<EventosParseables> aux = cola.front();
    cola.pop();
    return aux;
}
