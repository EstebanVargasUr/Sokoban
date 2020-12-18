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
                        if (BtnNivel1Spt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 2;
                        }
                        if (BtnNivel2Spt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 3;
                        }
                        if (BtnNivel3Spt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 4;
                        }
                        if (BtnNivel4Spt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 5;
                        }
                    }

                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                    {
                        if (BtnHomeSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 0;
                            Inicio = false;
                        }
                        if (BtnReiniciarSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Inicio = false;
                        }
                        if (BtnNivelesSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 1;
                            Inicio = false;
                        }
                    }

                }
                break;

            case Event::MouseMoved:

                break;
 
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Up || event.key.code == Keyboard::W)
                {
                    if (Escena != 0 && Escena != 1)
                    {
                        if (lista->mover("arriba")) {
                            nivel->casillas[lista->fila()][lista->columna()]->sprite.setTexture(nivel->getTexturaPersonajeAtras());
                            nivel->casillas[lista->fila()+1][lista->columna()]->sprite.setTexture(nivel->getTexturaFondo());

                            if (lista->getJugador()->arriba->data == '$' || lista->getJugador()->arriba->data == '!')
                            {
                                nivel->casillas[lista->fila() - 1][lista->columna()]->sprite.setTexture(nivel->getTexturaCaja());
                            }
                        }
                    }

                    
                }
                if (event.key.code == Keyboard::Down || event.key.code == Keyboard::S)
                {
                    if (Escena != 0 && Escena != 1)
                    {
                        if (lista->mover("abajo")) {
                            nivel->casillas[lista->fila()][lista->columna()]->sprite.setTexture(nivel->getTexturaPersonajeAtras());
                            nivel->casillas[lista->fila() - 1][lista->columna()]->sprite.setTexture(nivel->getTexturaFondo());

                            if (lista->getJugador()->abajo->data == '$' || lista->getJugador()->abajo->data == '!')
                            {
                                nivel->casillas[lista->fila() + 1][lista->columna()]->sprite.setTexture(nivel->getTexturaCaja());
                            }
                        }
                    }
                    
                }
                if (event.key.code == Keyboard::Left || event.key.code == Keyboard::A)
                {
                    if (Escena != 0 && Escena != 1)
                    {
                        if (lista->mover("izquierda")) {
                            nivel->casillas[lista->fila()][lista->columna()]->sprite.setTexture(nivel->getTexturaPersonajeAtras());
                            nivel->casillas[lista->fila()][lista->columna() + 1]->sprite.setTexture(nivel->getTexturaFondo());

                            if (lista->getJugador()->izquierda->data == '$' || lista->getJugador()->izquierda->data == '!')
                            {
                                nivel->casillas[lista->fila()][lista->columna() - 1]->sprite.setTexture(nivel->getTexturaCaja());
                            }
                        }
                        
                    }
                    
                }
                if (event.key.code == Keyboard::Right || event.key.code == Keyboard::D)
                {
                    if (Escena != 0 && Escena != 1)
                    {
                        if (lista->mover("derecha")) {
                            nivel->casillas[lista->fila()][lista->columna()]->sprite.setTexture(nivel->getTexturaPersonajeAtras());
                            nivel->casillas[lista->fila()][lista->columna() - 1]->sprite.setTexture(nivel->getTexturaFondo());

                            if (lista->getJugador()->derecha->data == '$' || lista->getJugador()->derecha->data == '!')
                            {
                                nivel->casillas[lista->fila()][lista->columna() + 1]->sprite.setTexture(nivel->getTexturaCaja());
                            }
                        }
                    }
                    
                }
                if (event.key.code == Keyboard::Escape)
                {
                    if (Escena != 0 && Escena != 1)
                    {
                        Escena = 0;
                        Inicio = false;
                    }
                }
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
    CargaGrafica CargaFondoMenu = CargaGrafica("MenuFondo.jpg", 0, 0, 1, 1, FondoMenuTx, FondoMenuSpt,0);
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
    CargaGrafica CargaBtnReiniciar = CargaGrafica("btnReiniciar.png", 1050, 200, 0.35, 0.35, BtnReiniciarTx, BtnReiniciarSpt, 1);
    CargaGrafica CargaBtnHome = CargaGrafica("btnHome.png", 1060, 310, 0.68, 0.7, BtnHomeTx, BtnHomeSpt, 1);
    CargaGrafica CargaBtnNiveles = CargaGrafica("btnNiveles.png", 1070, 410, 0.68, 0.7, BtnNivelesTx, BtnNivelesSpt, 1);
    CargaGrafica CargaBtnRepeticion = CargaGrafica("btnRepeticion.png", 1050, 500, 0.35, 0.35, BtnRepeticionTx, BtnRepeticionSpt, 1);
    CargaGrafica CargaBarraVictoria = CargaGrafica("BarraVictoria.png", 1050, 500, 0.35, 0.35, BtnRepeticionTx, BtnRepeticionSpt, 1);
    
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

        window.draw(FondoMenuSpt);
        window.draw(BtnNivel1Spt);
        window.draw(BtnNivel2Spt);
        window.draw(BtnNivel3Spt);
        window.draw(BtnNivel4Spt);
        window.draw(BtnNivel5Spt);
        window.draw(BtnDevolverSSpt);

        window.display();
    }
    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
    {
        if (Escena == 2) {
            if (!Inicio) {
                window.clear();
                nivel = new Nivel(1);
                CargarLista();

                CargaGrafica CargaMeta1 = CargaGrafica("Meta1.png", 300, 420, 0.15, 0.15, Meta1Tx, Meta1Spt, 1);
                CargaGrafica CargaMeta2 = CargaGrafica("Meta1.png", 840, 540, 0.15, 0.15, Meta2Tx, Meta2Spt, 1);
                CargaGrafica CargaMeta3 = CargaGrafica("Meta1.png", 720, 240, 0.15, 0.15, Meta3Tx, Meta3Spt, 1);
                Inicio = true;
            }
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    window.draw(nivel->casillas[i][j]->sprite);
                }
            }

            window.draw(Meta1Spt);
            window.draw(Meta2Spt);
            window.draw(Meta3Spt);
        }

        if (Escena == 3) {
            if (!Inicio) {
                window.clear();
                nivel = new Nivel(2);
                CargarLista();
                CargaGrafica CargaMeta1 = CargaGrafica("Meta1.png", 600, 240, 0.15, 0.15, Meta1Tx, Meta1Spt, 1);
                CargaGrafica CargaMeta2 = CargaGrafica("Meta1.png", 660, 240, 0.15, 0.15, Meta2Tx, Meta2Spt, 1);
                CargaGrafica CargaMeta3 = CargaGrafica("Meta1.png", 720, 240, 0.15, 0.15, Meta3Tx, Meta3Spt, 1);
                Inicio = true;
            }
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    window.draw(nivel->casillas[i][j]->sprite);
                }
            }

            window.draw(Meta1Spt);
            window.draw(Meta2Spt);
            window.draw(Meta3Spt);
        }
        if (Escena == 4) {
            if (!Inicio) {
                window.clear();
                nivel = new Nivel(3);
                CargarLista();
                CargaGrafica CargaMeta1 = CargaGrafica("Meta1.png", 420, 300, 0.15, 0.15, Meta1Tx, Meta1Spt, 1);
                CargaGrafica CargaMeta2 = CargaGrafica("Meta1.png", 420, 420, 0.15, 0.15, Meta2Tx, Meta2Spt, 1);
                CargaGrafica CargaMeta3 = CargaGrafica("Meta1.png", 660, 360, 0.15, 0.15, Meta3Tx, Meta3Spt, 1);
                CargaGrafica CargaMeta4 = CargaGrafica("Meta1.png", 600, 480, 0.15, 0.15, Meta4Tx, Meta4Spt, 1);
                CargaGrafica CargaMeta5 = CargaGrafica("Meta1.png", 540, 540, 0.15, 0.15, Meta5Tx, Meta5Spt, 1);
                CargaGrafica CargaMeta6 = CargaGrafica("Meta1.png", 600, 600, 0.15, 0.15, Meta6Tx, Meta6Spt, 1);
                CargaGrafica CargaMeta7 = CargaGrafica("Meta1.png", 720, 540, 0.15, 0.15, Meta7Tx, Meta7Spt, 1);
                Inicio = true;
            }
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    window.draw(nivel->casillas[i][j]->sprite);
                }
            }

            window.draw(Meta1Spt);
            window.draw(Meta2Spt);
            window.draw(Meta3Spt);
            window.draw(Meta4Spt);
            window.draw(Meta5Spt);
            window.draw(Meta6Spt);
            window.draw(Meta7Spt);
        }
        if (Escena == 5) {
            if (!Inicio) {
                window.clear();
                nivel = new Nivel(4);
                CargarLista();
                CargaGrafica CargaMeta1 = CargaGrafica("Meta1.png", 540, 300, 0.15, 0.15, Meta1Tx, Meta1Spt, 1);
                CargaGrafica CargaMeta2 = CargaGrafica("Meta1.png", 540, 360, 0.15, 0.15, Meta2Tx, Meta2Spt, 1);
                CargaGrafica CargaMeta3 = CargaGrafica("Meta1.png", 540, 420, 0.15, 0.15, Meta3Tx, Meta3Spt, 1);
                CargaGrafica CargaMeta4 = CargaGrafica("Meta1.png", 540, 480, 0.15, 0.15, Meta4Tx, Meta4Spt, 1);
                Inicio = true;
            }
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    window.draw(nivel->casillas[i][j]->sprite);
                }
            }

            window.draw(Meta1Spt);
            window.draw(Meta2Spt);
            window.draw(Meta3Spt);
            window.draw(Meta4Spt);
        }

        window.draw(BtnHomeSpt);
        window.draw(BtnReiniciarSpt);
        window.draw(BtnNivelesSpt);
        window.display();
    }
    
}

void Juego::CargarLista()
{
    lista = new Lista();

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 20; j++) {
            if (Escena == 2)
                lista->insertar(tabla1[i][j], i, j);
            else if (Escena == 3)
                lista->insertar(tabla2[i][j], i, j);
            else if (Escena == 4)
                lista->insertar(tabla3[i][j], i, j);
            else if (Escena == 5)
                lista->insertar(tabla4[i][j], i, j);
        }
    } 
}

