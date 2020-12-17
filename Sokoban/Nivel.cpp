#include "pch.h"
#include "Nivel.h"

Nivel::Nivel(int nivel) {
	filas = 15;
	columnas = 20;

	switch (nivel)
	{
	case 1:
		if (!TexturaFondo.loadFromFile("fondo1.jpg") || !TexturaMuro.loadFromFile("Muro1.png"))
		{
			cout << "No se cargo la imagen correctamente" << endl;
		}
		break;

	case 2:
		
		break;

	case 3:
		if (!TexturaFondo.loadFromFile("fondo1.jpg") || !TexturaMuro.loadFromFile("Muro3.jpg"))
		{
			cout << "No se cargo la imagen correctamente" << endl;
		}
		break;

	case 4:
		
		break;
	}

	if(!TexturaCaja.loadFromFile("caja1.png") || !TexturaCajaMeta.loadFromFile("caja2.png") || !TexturaMeta.loadFromFile("Meta1.png"))
	{
		cout << "No se cargo la imagen correctamente" << endl;
	}

	if (!TexturaPersonajeFrente.loadFromFile("PersonajeFrente.png") || !TexturaPersonajeAtras.loadFromFile("PersonajeAtras1.png") || 
		!TexturaPersonajeDerecha.loadFromFile("PersonajeDerecha.png") || !TexturaPersonajeIzquierda.loadFromFile("PersonajeIzquierda.png"))
	{
		cout << "No se cargo la imagen correctamente" << endl;;
	}

	setEstadoInicial(nivel);
}

void Nivel::setEstadoInicial(int nivel) {
	posicionJugador = Vector2i(8, 7); // ?
	setTablero(nivel);
}

void Nivel::setPosicionParedes() { // ?
	poscicionParedes.clear();
	poscicionParedes.push_back(Vector2i(3, 4));
	poscicionParedes.push_back(Vector2i(3, 5));
	poscicionParedes.push_back(Vector2i(3, 6));
	poscicionParedes.push_back(Vector2i(3, 7));
	poscicionParedes.push_back(Vector2i(3, 8));
	poscicionParedes.push_back(Vector2i(3, 9));
	poscicionParedes.push_back(Vector2i(3, 10));
	poscicionParedes.push_back(Vector2i(3, 11));
	poscicionParedes.push_back(Vector2i(3, 12));
	poscicionParedes.push_back(Vector2i(3, 13));
	poscicionParedes.push_back(Vector2i(4, 4));
	poscicionParedes.push_back(Vector2i(4, 13));
	poscicionParedes.push_back(Vector2i(4, 14));
	poscicionParedes.push_back(Vector2i(4, 15));
	poscicionParedes.push_back(Vector2i(5, 4));
	poscicionParedes.push_back(Vector2i(5, 6));
	poscicionParedes.push_back(Vector2i(5, 8));
	poscicionParedes.push_back(Vector2i(5, 15));
	poscicionParedes.push_back(Vector2i(6, 4));
	poscicionParedes.push_back(Vector2i(6, 9));
	poscicionParedes.push_back(Vector2i(6, 11));
	poscicionParedes.push_back(Vector2i(6, 13));
	poscicionParedes.push_back(Vector2i(6, 15));
	poscicionParedes.push_back(Vector2i(7, 4));
	poscicionParedes.push_back(Vector2i(7, 6));
	poscicionParedes.push_back(Vector2i(7, 13));
	poscicionParedes.push_back(Vector2i(7, 15));
	poscicionParedes.push_back(Vector2i(8, 4));
	poscicionParedes.push_back(Vector2i(8, 9));
	poscicionParedes.push_back(Vector2i(8, 10));
	poscicionParedes.push_back(Vector2i(8, 11));
	poscicionParedes.push_back(Vector2i(8, 15));
	poscicionParedes.push_back(Vector2i(9, 4));
	poscicionParedes.push_back(Vector2i(9, 5));
	poscicionParedes.push_back(Vector2i(9, 6));
	poscicionParedes.push_back(Vector2i(9, 15));
	poscicionParedes.push_back(Vector2i(10, 6));
	poscicionParedes.push_back(Vector2i(10, 7));
	poscicionParedes.push_back(Vector2i(10, 8));
	poscicionParedes.push_back(Vector2i(10, 12));
	poscicionParedes.push_back(Vector2i(10, 13));
	poscicionParedes.push_back(Vector2i(10, 14));
	poscicionParedes.push_back(Vector2i(10, 15));
	poscicionParedes.push_back(Vector2i(11, 8));
	poscicionParedes.push_back(Vector2i(11, 9));
	poscicionParedes.push_back(Vector2i(11, 10));
	poscicionParedes.push_back(Vector2i(11, 11));
	poscicionParedes.push_back(Vector2i(11, 12));
}

void Nivel::setNivel1() {
	//MUROS
	casillas[3][4]->setSprite(TexturaMuro);
	casillas[3][5]->setSprite(TexturaMuro);
	casillas[3][6]->setSprite(TexturaMuro);
	casillas[3][7]->setSprite(TexturaMuro);
	casillas[3][8]->setSprite(TexturaMuro);
	casillas[3][9]->setSprite(TexturaMuro);
	casillas[3][10]->setSprite(TexturaMuro);
	casillas[3][11]->setSprite(TexturaMuro);
	casillas[3][12]->setSprite(TexturaMuro);
	casillas[3][13]->setSprite(TexturaMuro);
	casillas[4][4]->setSprite(TexturaMuro);
	casillas[4][13]->setSprite(TexturaMuro);
	casillas[4][14]->setSprite(TexturaMuro);
	casillas[4][15]->setSprite(TexturaMuro);
	casillas[5][4]->setSprite(TexturaMuro);
	casillas[5][6]->setSprite(TexturaMuro);
	casillas[5][8]->setSprite(TexturaMuro);
	casillas[5][15]->setSprite(TexturaMuro);
	casillas[6][4]->setSprite(TexturaMuro);
	casillas[6][9]->setSprite(TexturaMuro);
	casillas[6][11]->setSprite(TexturaMuro);
	casillas[6][13]->setSprite(TexturaMuro);
	casillas[6][15]->setSprite(TexturaMuro);
	casillas[7][4]->setSprite(TexturaMuro);
	casillas[7][6]->setSprite(TexturaMuro);
	casillas[7][13]->setSprite(TexturaMuro);
	casillas[7][15]->setSprite(TexturaMuro);
	casillas[8][4]->setSprite(TexturaMuro);
	casillas[8][9]->setSprite(TexturaMuro);
	casillas[8][10]->setSprite(TexturaMuro);
	casillas[8][11]->setSprite(TexturaMuro);
	casillas[8][15]->setSprite(TexturaMuro);
	casillas[9][4]->setSprite(TexturaMuro);
	casillas[9][5]->setSprite(TexturaMuro);
	casillas[9][6]->setSprite(TexturaMuro);
	casillas[9][15]->setSprite(TexturaMuro);
	casillas[10][6]->setSprite(TexturaMuro);
	casillas[10][7]->setSprite(TexturaMuro);
	casillas[10][8]->setSprite(TexturaMuro);
	casillas[10][12]->setSprite(TexturaMuro);
	casillas[10][13]->setSprite(TexturaMuro);
	casillas[10][14]->setSprite(TexturaMuro);
	casillas[10][15]->setSprite(TexturaMuro);
	casillas[11][8]->setSprite(TexturaMuro);
	casillas[11][9]->setSprite(TexturaMuro);
	casillas[11][10]->setSprite(TexturaMuro);
	casillas[11][11]->setSprite(TexturaMuro);
	casillas[11][12]->setSprite(TexturaMuro);
	//PERSONAJE
	casillas[10][10]->setSprite(TexturaPersonajeAtras);
	//METAS
	casillas[4][12]->setSprite(TexturaMeta);
	casillas[7][5]->setSprite(TexturaMeta);
	casillas[9][14]->setSprite(TexturaMeta);
	//CAJAS
	casillas[6][7]->setSprite(TexturaCaja);
	casillas[7][11]->setSprite(TexturaCaja);
	casillas[8][7]->setSprite(TexturaCaja);

}

void Nivel::setNivel2() {

}
void Nivel::setNivel3() {
	//MUROS
	casillas[3][8]->setSprite(TexturaMuro);
	casillas[3][9]->setSprite(TexturaMuro);
	casillas[3][10]->setSprite(TexturaMuro);
	casillas[3][11]->setSprite(TexturaMuro);
	casillas[3][12]->setSprite(TexturaMuro);

	casillas[4][6]->setSprite(TexturaMuro);
	casillas[4][7]->setSprite(TexturaMuro);
	casillas[4][8]->setSprite(TexturaMuro);
	casillas[4][12]->setSprite(TexturaMuro);

	casillas[5][6]->setSprite(TexturaMuro);
	casillas[5][12]->setSprite(TexturaMuro);

	casillas[6][6]->setSprite(TexturaMuro);
	casillas[6][7]->setSprite(TexturaMuro);
	casillas[6][8]->setSprite(TexturaMuro);
	casillas[6][12]->setSprite(TexturaMuro);

	casillas[7][6]->setSprite(TexturaMuro);
	casillas[7][8]->setSprite(TexturaMuro);
	casillas[7][9]->setSprite(TexturaMuro);
	casillas[7][12]->setSprite(TexturaMuro);

	casillas[8][6]->setSprite(TexturaMuro);
	casillas[8][8]->setSprite(TexturaMuro);
	casillas[8][12]->setSprite(TexturaMuro);
	casillas[8][13]->setSprite(TexturaMuro);

	casillas[9][6]->setSprite(TexturaMuro);
	casillas[9][13]->setSprite(TexturaMuro);

	casillas[10][6]->setSprite(TexturaMuro);
	casillas[10][13]->setSprite(TexturaMuro);

	casillas[11][6]->setSprite(TexturaMuro);
	casillas[11][7]->setSprite(TexturaMuro);
	casillas[11][8]->setSprite(TexturaMuro);
	casillas[11][9]->setSprite(TexturaMuro);
	casillas[11][10]->setSprite(TexturaMuro);
	casillas[11][11]->setSprite(TexturaMuro);
	casillas[11][12]->setSprite(TexturaMuro);
	casillas[11][13]->setSprite(TexturaMuro);

	//PERSONAJE
	casillas[5][8]->setSprite(TexturaPersonajeAtras);
	//METAS
	casillas[5][7]->setSprite(TexturaMeta);
	casillas[6][11]->setSprite(TexturaMeta);
	casillas[7][7]->setSprite(TexturaMeta);
	casillas[8][10]->setSprite(TexturaMeta);
	casillas[9][12]->setSprite(TexturaMeta);
	casillas[10][10]->setSprite(TexturaMeta);
	//CAJAS
	casillas[5][9]->setSprite(TexturaCaja);
	casillas[6][10]->setSprite(TexturaCaja);
	casillas[7][10]->setSprite(TexturaCaja);
	casillas[9][7]->setSprite(TexturaCaja);
	casillas[9][10]->setSprite(TexturaCaja);
	casillas[9][11]->setSprite(TexturaCaja);
	//CAJA COLOCADA
	casillas[9][9]->setSprite(TexturaCajaMeta);
}
void Nivel::setNivel4() {

}

void Nivel::setTablero(int nivel) {
	casillas.clear();

	int aum = 0;
	int aum2 = 0;

	for (int j = 0; j < 15; j++)
	{
		aum = 0;
		vector<Tablero*> Fila;

		for (int i = 0; i < 20; i++)
		{
			Fila.push_back(new Tablero(TexturaFondo, aum, aum2));
			aum = aum + 60;
		}
		casillas.push_back(Fila);
		aum2 = aum2 + 60;
	}

	switch (nivel)
	{
	case 1:
		setNivel1();
		break;

	case 2:
		setNivel2();
		break;

	case 3:
		setNivel3();
		break;

	case 4:
		setNivel4();
		break;
	}
}