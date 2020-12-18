#include "pch.h"
#include "Tablero.h"
#include "Nivel.h"

Tablero::Tablero(Texture &_textura, float x, float y, bool fondo) {

	setSprite(_textura,fondo);

	posicion = Vector2f(x, y);
	sprite.setPosition(posicion);
}

void Tablero::setSprite(Texture &_textura,bool fondo) {

	if (fondo == true)
	{
		sprite.setScale(0.15, 0.15);
		return;
	}
	
	_textura.setSmooth(true);
	sprite.setTexture(_textura);
}