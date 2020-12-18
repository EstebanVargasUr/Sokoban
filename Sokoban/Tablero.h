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

	Tablero(Texture&,float,float,bool); //Nombre textura, pos x, pos y

	void setSprite(Texture&,bool); //String para la textura
	
};
#endif 