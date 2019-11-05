//
// Created by diego on 23/10/19.
//

#include "Textura.h"
#include "../Excepciones/ExcepcionConPos.h"
#include "../Vista/Camara.h"
#include <SDL2/SDL_image.h>
#include <iostream>

Textura::Textura(SDL_Renderer *renderizador, const std::string &archivo, Posicion* pos) : posicion(pos) {
    textura = IMG_LoadTexture(renderizador, archivo.c_str());
    if(textura == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, SDL_GetError());
    }
}

Textura::Textura(Textura&& text) noexcept : posicion(text.posicion) {
    this->textura = text.textura;
    text.posicion = nullptr;
    text.textura = nullptr;
}

void Textura::copiar(SDL_Renderer *renderizador, Camara& camara) {
    if(posicion == nullptr){
        if(SDL_RenderCopyEx(renderizador, textura, nullptr, nullptr, -180, nullptr, SDL_FLIP_VERTICAL)<0){
            throw ExcepcionConPos(__FILE__, __LINE__, SDL_GetError());
        }
    } else {
        if(!camara.estaEnRango(posicion->getPosicion())){
            return;
        }
        SDL_Rect posImpresion = camara.obtenerPosImpresion(posicion->getPosicion());
        if(SDL_RenderCopyEx(renderizador, textura, nullptr, &posImpresion,\
        camara.obtenerAngulo(posicion->getAngulo()), nullptr, SDL_FLIP_NONE)<0){
            throw ExcepcionConPos(__FILE__, __LINE__, SDL_GetError());
        }
    }
}

void Textura::destruir() {
    if(textura != nullptr){
        SDL_DestroyTexture(textura);
    }
    textura = nullptr;
}

Textura::~Textura() {
    if(textura != nullptr){
        SDL_DestroyTexture(textura);
    }
}

Textura &Textura::operator=(const Textura &text) {
    this->posicion = text.posicion;
    this->textura = text.textura;
}
