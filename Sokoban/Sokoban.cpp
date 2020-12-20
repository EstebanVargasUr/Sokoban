#include "pch.h"
#include "Juego.h"
#include "Lista.h"

using namespace std;


int main()
{
    Juego* Ventana;
    Ventana = new Juego();
    Ventana->CargarJuego();
    
    system("PAUSE");
    return 0;
}
