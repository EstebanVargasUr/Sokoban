#include "pch.h"
#include "Lista.h"

Lista::Lista()
{
	inicial = NULL;
	anterior = NULL;
	jugador = NULL;
}

void Lista::insertar(char dato, int fila, int columna)
{
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->data = dato;
	nuevoNodo->fila = fila;
	nuevoNodo->columna = columna;

	if (inicial == NULL) {
		inicial = nuevoNodo;
		anterior = inicial;
	}
	else {

		if (fila == 0) {
			nuevoNodo->izquierda = anterior;
			anterior->derecha = nuevoNodo;
			anterior = nuevoNodo;
		}
		else {
			if (anterior->columna == 19) {
				Nodo* ultimoAbajo = inicial;
				while (ultimoAbajo->abajo != NULL) {
					ultimoAbajo = ultimoAbajo->abajo;
				}
				nuevoNodo->arriba = ultimoAbajo;
				ultimoAbajo->abajo = nuevoNodo;
				anterior = nuevoNodo;
			}
			else {
				Nodo* aux = inicial;
				Nodo* aux2 = inicial;

				while (aux->fila != fila - 1) {
					aux = aux->abajo;
				}
				while (aux->columna != columna) {
					aux = aux->derecha;
				}
				while (aux2->abajo != NULL) {
					aux2 = aux2->abajo;
				}
				while (aux2->derecha != NULL) {
					aux2 = aux2->derecha;
				}

				nuevoNodo->arriba = aux;
				nuevoNodo->izquierda = aux2;
				aux->abajo = nuevoNodo;
				aux2->derecha = nuevoNodo;
				anterior = nuevoNodo;
			}
		}
	}
	if (dato == '@')
		jugador = nuevoNodo;
}

bool Lista::mover(string pos)
{
	//if(jugador->arriba->data == ' ')
	return false;
}

void Lista::mostrar()
{
	Nodo* ini = inicial;
	//fila 0
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
	//fila 1
	ini = inicial->abajo;
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
	//fila 2
	ini = inicial->abajo->abajo;
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
	//fila 3
	ini = inicial->abajo->abajo->abajo;
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
	//fila 4
	ini = inicial->abajo->abajo->abajo->abajo;
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
	//fila 5
	ini = inicial->abajo->abajo->abajo->abajo->abajo;
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
	//fila 6
	ini = inicial->abajo->abajo->abajo->abajo->abajo->abajo;
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
	//fila 7
	ini = inicial->abajo->abajo->abajo->abajo->abajo->abajo->abajo;
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
	//fila 8
	ini = inicial->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo;
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
	//fila 9
	ini = inicial->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo;
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
	//fila 10
	ini = inicial->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo;
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
	//fila 11
	ini = inicial->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo;
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
	//fila 12
	ini = inicial->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo;
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
	//fila 13
	ini = inicial->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo;
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
	//fila 14
	ini = inicial->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo->abajo;
	while (ini != NULL)
	{
		cout << " -> " << ini->data;
		ini = ini->derecha;
	}
	cout << endl;
}

