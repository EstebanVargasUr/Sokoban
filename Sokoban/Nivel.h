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

	void setTablero(int);
	
	void setNivel1();
	void setNivel2();
	void setNivel3();
	void setNivel4();

public:
	Nivel(int);
	vector<vector<Tablero*>> casillas;

	Texture& getTexturaPersonajeAtras();
	Texture& getTexturaPersonajeDerecha();
	Texture& getTexturaPersonajeIzquierda();
	Texture& getTexturaPersonajeFrente();
	Texture& getTexturaFondo();
	Texture& getTexturaCaja();

};

#endif