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
	if (dato == '@' || dato == '*')
		jugador = nuevoNodo;
}

bool Lista::mover(string pos)
{
	if (pos == "arriba") {
		return arriba();
	}
	else if (pos == "abajo") {
		return abajo();
	}
	else if (pos == "izquierda") {
		return izquierda();
	}
	else if (pos == "derecha") {
		return derecha();
	}
	else {
		return false;
	}
}

bool Lista::arriba()
{
	if (jugador->arriba->data == ' ') {
		if (jugador->data == '@')
			jugador->data = ' ';
		else
			jugador->data = '.';

		jugador->arriba->data = '@';
		jugador = jugador->arriba;
		return true;
	}
	else if (jugador->arriba->data == '.') {
		if (jugador->data == '@')
			jugador->data = ' ';
		else
			jugador->data = '.';

		jugador->arriba->data = '*';
		jugador = jugador->arriba;
		return true;
	}
	else if (jugador->arriba->data == '$') {
		if (jugador->arriba->arriba->data == ' ') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->arriba->data = '@';
			jugador->arriba->arriba->data = '$';
			jugador = jugador->arriba;
			return true;
		}
		else if (jugador->arriba->arriba->data == '.') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->arriba->data = '@';
			jugador->arriba->arriba->data = '!';
			jugador = jugador->arriba;
			return true;
		}
		else {
			return false;
		}
	}
	else if (jugador->arriba->data == '!') {
		if (jugador->arriba->arriba->data == ' ') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->arriba->data = '*';
			jugador->arriba->arriba->data = '$';
			jugador = jugador->arriba;
			return true;
		}
		else if (jugador->arriba->arriba->data == '.') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->arriba->data = '*';
			jugador->arriba->arriba->data = '!';
			jugador = jugador->arriba;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Lista::abajo()
{
	if (jugador->abajo->data == ' ') {
		if (jugador->data == '@')
			jugador->data = ' ';
		else
			jugador->data = '.';

		jugador->abajo->data = '@';
		jugador = jugador->abajo;
		return true;
	}
	else if (jugador->abajo->data == '.') {
		if (jugador->data == '@')
			jugador->data = ' ';
		else
			jugador->data = '.';

		jugador->abajo->data = '*';
		jugador = jugador->abajo;
		return true;
	}
	else if (jugador->abajo->data == '$') {
		if (jugador->abajo->abajo->data == ' ') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->abajo->data = '@';
			jugador->abajo->abajo->data = '$';
			jugador = jugador->abajo;
			return true;
		}
		else if (jugador->abajo->abajo->data == '.') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->abajo->data = '@';
			jugador->abajo->abajo->data = '!';
			jugador = jugador->abajo;
			return true;
		}
		else {
			return false;
		}
	}
	else if (jugador->abajo->data == '!') {
		if (jugador->abajo->abajo->data == ' ') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->abajo->data = '*';
			jugador->abajo->abajo->data = '$';
			jugador = jugador->abajo;
			return true;
		}
		else if (jugador->abajo->abajo->data == '.') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->abajo->data = '*';
			jugador->abajo->abajo->data = '!';
			jugador = jugador->abajo;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Lista::izquierda()
{
	if (jugador->izquierda->data == ' ') {
		if (jugador->data == '@')
			jugador->data = ' ';
		else
			jugador->data = '.';

		jugador->izquierda->data = '@';
		jugador = jugador->izquierda;
		return true;
	}
	else if (jugador->izquierda->data == '.') {
		if (jugador->data == '@')
			jugador->data = ' ';
		else
			jugador->data = '.';

		jugador->izquierda->data = '*';
		jugador = jugador->izquierda;
		return true;
	}
	else if (jugador->izquierda->data == '$') {
		if (jugador->izquierda->izquierda->data == ' ') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->izquierda->data = '@';
			jugador->izquierda->izquierda->data = '$';
			jugador = jugador->izquierda;
			return true;
		}
		else if (jugador->izquierda->izquierda->data == '.') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->izquierda->data = '@';
			jugador->izquierda->izquierda->data = '!';
			jugador = jugador->izquierda;
			return true;
		}
		else {
			return false;
		}
	}
	else if (jugador->izquierda->data == '!') {
		if (jugador->izquierda->izquierda->data == ' ') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->izquierda->data = '*';
			jugador->izquierda->izquierda->data = '$';
			jugador = jugador->izquierda;
			return true;
		}
		else if (jugador->izquierda->izquierda->data == '.') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->izquierda->data = '*';
			jugador->izquierda->izquierda->data = '!';
			jugador = jugador->izquierda;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Lista::derecha()
{
	if (jugador->derecha->data == ' ') {
		if (jugador->data == '@')
			jugador->data = ' ';
		else
			jugador->data = '.';

		jugador->derecha->data = '@';
		jugador = jugador->derecha;
		return true;
	}
	else if (jugador->derecha->data == '.') {
		if (jugador->data == '@')
			jugador->data = ' ';
		else
			jugador->data = '.';

		jugador->derecha->data = '*';
		jugador = jugador->derecha;
		return true;
	}
	else if (jugador->derecha->data == '$') {
		if (jugador->derecha->derecha->data == ' ') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->derecha->data = '@';
			jugador->derecha->derecha->data = '$';
			jugador = jugador->derecha;
			return true;
		}
		else if (jugador->derecha->derecha->data == '.') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->derecha->data = '@';
			jugador->derecha->derecha->data = '!';
			jugador = jugador->derecha;
			return true;
		}
		else {
			return false;
		}
	}
	else if (jugador->derecha->data == '!') {
		if (jugador->derecha->derecha->data == ' ') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->derecha->data = '*';
			jugador->derecha->derecha->data = '$';
			jugador = jugador->derecha;
			return true;
		}
		else if (jugador->derecha->derecha->data == '.') {
			if (jugador->data == '@')
				jugador->data = ' ';
			else
				jugador->data = '.';

			jugador->derecha->data = '*';
			jugador->derecha->derecha->data = '!';
			jugador = jugador->derecha;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void Lista::mostrar()
{

	cout << "\n\n\n	PRUEBAS\n" << endl;
	Nodo* aux = new Nodo();
	Nodo* aux2 = new Nodo();
	aux = inicial;
	aux2 = inicial;
	while (aux != NULL)
	{
		aux2 = aux;
		while (aux2 != NULL)
		{
			cout << "----> Dato: " << aux2->data << " | Fila: " << aux2->fila << " Columna: " << aux2->columna << " | " << endl;
			
			cout << endl;

			aux2 = aux2->derecha;
		}
		aux = aux->abajo;
	}

	cout << endl;
}

	/*Nodo* ini = inicial;
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
*/
