#include "pch.h"
#include "Tablero.h"

Tablero::Tablero(Texture &_textura, float x, float y) {

	if (!setSprite(_textura))
	{
		return;
	}
	posicion = Vector2f(x, y);
	sprite.setPosition(posicion);

}

bool Tablero::setSprite(Texture &_textura) {

	_textura.setSmooth(true);
	sprite.setTexture(_textura);
	sprite.setScale(0.15, 0.15);
	
	return true;
}