#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;
using namespace std;

class Juego
{
private:

	//Ventana
	RenderWindow window;
	Event event;
	//Texturas
	
	//Sprites
	public:

	void CargarJuego();
	void Cargartexturas();
	void CargaEscenas();
	void ManejoBolasLvl1();
	void ManejoBolasLvl2();
	void ManejoBolasLvl3();
	void ManejoBolasLvl4();
	void ManejoBolasLvl5();
	int saberXY(int,int);
	void Victoria();
	void Movimientos();
};

