#include "Lista.h"

Lista::Lista()
{
}

void Lista::insertar(char dato, int fila, int columna)
{
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->data = dato;

	if (inicial == NULL) {
		nuevoNodo->fila = fila;
		nuevoNodo->columna = columna;
		nuevoNodo->data = dato;
		inicial = nuevoNodo;
	}
	else {
		Nodo* aux = inicial;

	}
}

bool Lista::mover(string pos)
{
}
