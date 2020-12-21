#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;
using namespace std;

#ifndef CARGAGRAFICA_H
#define CARGAGRAFICA_H

class CargaGrafica {
	public:
		Vector2f posicion;
		CargaGrafica(string, float, float,float, float, Texture&, Sprite&, int);
};
#endif