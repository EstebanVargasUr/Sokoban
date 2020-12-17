#include "pch.h"
#include "Juego.h"
#include "Tablero.h"
#include "Nivel.h"

void Juego::CargarJuego() {
    window.create(VideoMode(1200, 900), "Sokoban", Style::Close);
    
    icono.loadFromFile("icono.png");
    window.setIcon(icono.getSize().x, icono.getSize().y, icono.getPixelsPtr());
    Cargartexturas();
    
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            // window closed
            case Event::Closed:
                // "close requested" event: we close the window
                window.close();
                break;

            // key pressed
            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left)
                {
                    if (Escena == 0) {
                        if (BtnJugarSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 1;
                        }
                        if (BtnSalirSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            window.close();
                        }
                    }
                    if (Escena == 1) {
                        if (BtnDevolverSSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 0;
                        }
                    }

                }
                break;

            case Event::MouseMoved:

                break;
 
            default:
                break;
            }

        }
      //  Victoria();
        CargaEscenas();
    }
}
void Juego::Cargartexturas() {
    CargaGrafica CargaFondoMenu = CargaGrafica("MenuFondo.jpg", 0, 0, 1, 1, FondoMenuTx, FondoMenuSpt,0);;
    CargaGrafica CargaLogo = CargaGrafica("logoSokoban.png",405,100,0.65,0.65, LogoTx, LogoSpt,1);
    CargaGrafica CargaBtnJugar = CargaGrafica("btnJugar.png", 400, 390, 0.9, 0.9, BtnJugarTx, BtnJugarSpt,1);
    CargaGrafica CargaBtnCargar = CargaGrafica("btnCargarPartida.png", 400, 510, 0.9, 0.9, BtnCargarPartidaTx, BtnCargarPartidaSpt, 1);
    CargaGrafica CargaBtnSalir = CargaGrafica("btnSalir.png", 400, 630, 0.9, 0.9, BtnSalirTx, BtnSalirSpt, 1);
    CargaGrafica CargaBtnNivel1 = CargaGrafica("btnNivel1.png", 160, 300, 0.75, 0.75, BtnNivel1Tx, BtnNivel1Spt, 1);
    CargaGrafica CargaBtnNivel2 = CargaGrafica("btnNivel2.png", 360, 500, 0.75, 0.75, BtnNivel2Tx, BtnNivel2Spt, 1);
    CargaGrafica CargaBtnNivel3 = CargaGrafica("btnNivel3.png", 560, 300, 0.75, 0.75, BtnNivel3Tx, BtnNivel3Spt, 1);
    CargaGrafica CargaBtnNivel4 = CargaGrafica("btnNivel4.png", 760, 500, 0.75, 0.75, BtnNivel4Tx, BtnNivel4Spt, 1);
    CargaGrafica CargaBtnNivel5 = CargaGrafica("btnNivel5.png", 960, 300, 0.75, 0.75, BtnNivel5Tx, BtnNivel5Spt, 1);
    CargaGrafica CargaBtnDelvolverS = CargaGrafica("btnDevolverS.png", 80, 800, 0.50, 0.65, BtnDevolverSTx, BtnDevolverSSpt, 1);
}
void Juego::CargaEscenas() {

    if (Escena == 0) {
        window.clear();
        window.draw(FondoMenuSpt);
        window.draw(LogoSpt);
        window.draw(BtnJugarSpt);
        window.draw(BtnCargarPartidaSpt);
        window.draw(BtnSalirSpt);
        window.display();
    }
    if (Escena == 1) {
        window.clear();

        nivel = new Nivel(1);

        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                window.draw(nivel->casillas[i][j]->sprite);
            }
        }

        /*window.draw(FondoMenuSpt);
        window.draw(BtnNivel1Spt);
        window.draw(BtnNivel2Spt);
        window.draw(BtnNivel3Spt);
        window.draw(BtnNivel4Spt);
        window.draw(BtnNivel5Spt);
        window.draw(BtnDevolverSSpt);*/
        window.display();
    }
}

