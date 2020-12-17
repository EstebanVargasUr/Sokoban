#pragma once
#include "SFML\Graphics.hpp"
#include "CargaGrafica.h"
#include <vector>
using namespace sf;
using namespace std;

#ifndef JUEGO_H
#define JUEGO_H

class Juego
{
private:
	//Ventana
	RenderWindow window;
	Event event;
	Image icono;
	int Escena = 0;
	//Texturas
	Texture FondoMenuTx;
	Texture LogoTx;
	Texture BtnJugarTx;
	Texture BtnCargarPartidaTx;
	Texture BtnSalirTx;
	Texture BtnNivel1Tx;
	Texture BtnNivel2Tx;
	Texture BtnNivel3Tx;
	Texture BtnNivel4Tx;
	Texture BtnNivel5Tx;
	Texture BtnDevolverSTx;
	//Sprites
	Sprite FondoMenuSpt;
	Sprite LogoSpt;
	Sprite BtnJugarSpt;
	Sprite BtnCargarPartidaSpt;
	Sprite BtnSalirSpt;
	Sprite BtnNivel1Spt;
	Sprite BtnNivel2Spt;
	Sprite BtnNivel3Spt;
	Sprite BtnNivel4Spt;
	Sprite BtnNivel5Spt;
	Sprite BtnDevolverSSpt;

	public:

	void CargarJuego();
	void Cargartexturas();
	void CargaEscenas();
	
};
#endif
