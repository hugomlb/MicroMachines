//
// Created by diego on 22/10/19.
//

#include <iostream>
#include "HiloVisualizacion.h"
#include "../Excepciones/ExcepcionConPos.h"

HiloVisualizacion::HiloVisualizacion(Servidor& servidor) : renderizador("microMachines.exe", 1000, 1000)\
, servidor(servidor), camara(renderizador) {
}

void HiloVisualizacion::run() {
    try{
        renderizador.copiarTodo();
        renderizador.imprimir(1000);
        std::vector<int> mensaje = servidor.recibir();
        while(mensaje[0] != -1){
            renderizador.limpiar();
            renderizador.copiarTodo();
            renderizador.imprimir(20);
            camara.actualizar(mensaje);
            mensaje = servidor.recibir();
            //camara.actualizar(mensaje);
        }
    } catch(const ExcepcionConPos& e){
        std::cerr<<e.what()<<'\n';
    } catch (std::exception& e) {
        std::cerr<<e.what()<<'\n';
    } catch (...) {
        std::cerr<<"Error desconocido\n";
    }
}
