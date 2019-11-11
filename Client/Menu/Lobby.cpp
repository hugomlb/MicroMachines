//
// Created by diego on 6/11/19.
//

#include <iostream>
#include "Lobby.h"

Lobby::Lobby(ServidorProxy &servidor, QWidget* parent) : servidor(servidor) {
    Ui::Lobby lobby;
    lobby.setupUi(this);
    std::vector<std::string> partidas = servidor.obtenerPartidas();
    copiarPistas(partidas);
    conectar();
}

void Lobby::conectar() {
    QObject::connect(findChild<QPushButton*>("crear"), &QPushButton::clicked, this, &Lobby::crearPartida);
    QObject::connect(findChild<QPushButton*>("crear"), &QPushButton::clicked, this, &QWidget::close);
}

void Lobby::crearPartida() {
    std::string nombre = findChild<QLineEdit*>("nombre")->text().toStdString();
    std::string cantJugadores = findChild<QLineEdit*>("cantJug")->text().toStdString();
    servidor.crearPartida(nombre, cantJugadores);
    servidor.elegirPartida(nombre);
}

void Lobby::copiarPistas(std::vector<std::string> &partidas) {
    if(!partidas.empty()){
        QObject::connect(findChild<QPushButton*>("pista1"), &QPushButton::clicked, this, &Lobby::unirPartida);
        QObject::connect(findChild<QPushButton*>("pista1"), &QPushButton::clicked, this, &QWidget::close);
        findChild<QPushButton*>("pista1")->setText(QString::fromUtf8(partidas[0].c_str()));
    }
    if(partidas.size() > 1){
        QObject::connect(findChild<QPushButton*>("pista2"), &QPushButton::clicked, this, &Lobby::unirPartida);
        QObject::connect(findChild<QPushButton*>("pista2"), &QPushButton::clicked, this, &QWidget::close);
        findChild<QPushButton*>("pista2")->setText(QString::fromUtf8(partidas[1].c_str()));
    }
    if(partidas.size() > 2){
        QObject::connect(findChild<QPushButton*>("pista3"), &QPushButton::clicked, this, &Lobby::unirPartida);
        QObject::connect(findChild<QPushButton*>("pista3"), &QPushButton::clicked, this, &QWidget::close);
        findChild<QPushButton*>("pista3")->setText(QString::fromUtf8(partidas[2].c_str()));
    }
    if(partidas.size() > 3){
        QObject::connect(findChild<QPushButton*>("pista4"), &QPushButton::clicked, this, &Lobby::unirPartida);
        QObject::connect(findChild<QPushButton*>("pista4"), &QPushButton::clicked, this, &QWidget::close);
        findChild<QPushButton*>("pista4")->setText(QString::fromUtf8(partidas[3].c_str()));
    }
    if(partidas.size() > 4){
        QObject::connect(findChild<QPushButton*>("pista5"), &QPushButton::clicked, this, &Lobby::unirPartida);
        QObject::connect(findChild<QPushButton*>("pista5"), &QPushButton::clicked, this, &QWidget::close);
        findChild<QPushButton*>("pista5")->setText(QString::fromUtf8(partidas[4].c_str()));
    }
}

void Lobby::unirPartida() {
    auto* boton = qobject_cast<QPushButton*>(sender());
    servidor.elegirPartida(boton->text().toStdString());
}

