#pragma once
#include "pch.h"

#ifndef LISTA_H
#define LISTA_H

typedef struct  Nodo {
    char data;
    int fila, columna;
    struct Nodo* arriba, * abajo, * izquierda, * derecha;
};

class Lista {

private:
    Nodo* inicial;

public:
    Lista();
    void insertar(char,int,int);
    bool mover(string);
};

#endif