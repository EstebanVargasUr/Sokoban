#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>
#include "Tablero.h"
#include "CargaGrafica.h"
#include <vector>

using namespace std;
using namespace sf;

#ifndef Nivel_H
#define Nivel_H


class Nivel {

private:
	Texture TexturaFondo;
	Texture TexturaCaja;
	Texture TexturaMuro;
	Texture TexturaMeta;
	Texture TexturaCajaMeta;
	Texture TexturaPersonajeAtras;
	Texture TexturaPersonajeDerecha;
	Texture TexturaPersonajeIzquierda;
	Texture TexturaPersonajeFrente;

	Vector2i posicionSalida;
	Vector2i posicionJugador;
	vector<Vector2i> poscicionParedes;
	vector<Vector2i> poscicionCajas;
	vector<Vector2i> poscicionMetas;

	void setPosicionParedes(); // ?
	void setEstadoInicial(int);
	void setTablero(int);
	
	void setNivel1();
	void setNivel2();
	void setNivel3();
	void setNivel4();

public:
	vector<vector<Tablero*>> casillas;
	int filas;
	int columnas;

	Nivel(int);
};

#endif