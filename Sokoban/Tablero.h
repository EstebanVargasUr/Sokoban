#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

#ifndef TABLERO_H
#define TABLERO_H


class Tablero {

public:

	Vector2f posicion;
	Texture textura;
	Sprite sprite;

	Tablero(Texture&,float,float); //Nombre textura, pos x, pos y

	bool setSprite(Texture&); //String para la textura
	
};
#endif 