//
// Created by diego on 24/10/19.
//

#include <iostream>
#include "Posicion.h"

Posicion::Posicion(int posX, int posY, int ancho, int altura, int angulo) {
    posicion.x = posX;
    posicion.y = posY;
    posicion.w = ancho;
    posicion.h = altura;
    this->angulo = angulo;
}

SDL_Rect Posicion::getRect() {
    return posicion;
}

void Posicion::moverA(int posX, int posY) {
    posicion.x = posX;
    posicion.y = posY;
}

Posicion Posicion::operator-(Posicion const &pos) {
    return {posicion.x-pos.posicion.x, posicion.y-pos.posicion.y, posicion.w, posicion.h, angulo};
}

void Posicion::mover(Posicion& pos) {
    posicion.x += pos.posicion.x;
    posicion.y += pos.posicion.y;
}

void Posicion::rotar(int angulo) {
    this->angulo = angulo;
}

int Posicion::getAngulo() {
    return angulo;
}

bool Posicion::estaEnRango(int ancho, int largo) {
    if(posicion.x - posicion.w < 0 || posicion.x > ancho){
        return false;
    }
    return !((posicion.y - posicion.h) < 0 || posicion.y > largo);
}
