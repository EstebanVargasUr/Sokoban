#include "pch.h"
#include "CargaGrafica.h"

CargaGrafica::CargaGrafica(string archivo, float x, float y,float s1, float s2, Texture &textura, Sprite &sprite, int cual) {
	if (cual == 1) {
		textura.loadFromFile(archivo);
		sprite.setTexture(textura);
		posicion = Vector2f(x, y);
		sprite.setPosition(posicion); ;
		sprite.setScale(s1, s2);
	}
	if (cual == 0) {
		textura.loadFromFile(archivo);
		sprite.setTexture(textura);
		sprite.setScale(s1, s2);
	}
	
}
