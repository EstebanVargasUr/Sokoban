#pragma once
#include "pch.h"

#ifndef LISTA_H
#define LISTA_H

struct  Nodo {
    char data;
    int fila, columna;
    struct Nodo* arriba, * abajo, * izquierda, * derecha;
};

class Lista {

private:
    Nodo* inicial;
    Nodo* anterior;
    Nodo* jugador;

public:
    Lista();
    void insertar(char,int,int);
    bool mover(string);
    bool arriba();
    bool abajo();
    bool izquierda();
    bool derecha();
    void mostrar();
    int fila();
    int columna();

    Nodo* getJugador();
};

#endif