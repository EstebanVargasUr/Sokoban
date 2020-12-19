#include "pch.h"
#include "Juego.h"
#include "Tablero.h"
#include "Nivel.h"

void Juego::CargarJuego() {
    window.create(VideoMode(1200, 900), "Sokoban", Style::Close);
    
    icono.loadFromFile("imagenes/icono.png");
    window.setIcon(icono.getSize().x, icono.getSize().y, icono.getPixelsPtr());
    
    Cargartexturas();
    CargarSonidos();
    
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
                            Inicio = false;
                        }
                        if (BtnSalirSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            MusicaInicial.stop();
                            window.close();
                        }
                    }
                    if (Escena == 1) {
                        if (BtnDevolverSSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 0;
                            Inicio = false;
                        }
                        if (BtnNivel1Spt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 2;
                            Inicio = false;
                        }
                        if (BtnNivel2Spt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 3;
                            Inicio = false;
                        }
                        if (BtnNivel3Spt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 4;
                            Inicio = false;
                        }
                        if (BtnNivel4Spt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 5;
                            Inicio = false;
                        }
                    }

                    if (Escena == 2 || Escena == 3 || Escena == 4 || Escena == 5)
                    {
                        if (BtnHomeSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 0;
                            while (lista->puntaje.empty() == false) {
                                lista->puntaje.pop();
                            }
                            Inicio = false;
                        }
                        if (BtnReiniciarSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            while (lista->puntaje.empty() == false) {
                                lista->puntaje.pop();
                            }
                            Inicio = false;
                        }
                        if (BtnNivelesSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = 1;
                            while (lista->puntaje.empty() == false) {
                                lista->puntaje.pop();
                            }
                            Inicio = false;
                        }
                        if (Escena == 5) {
                            if (BtnSiguienteSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                            {
                                Escena = 0;
                                while (lista->puntaje.empty() == false) {
                                    lista->puntaje.pop();
                                }
                                Inicio = false;
                            }
                        }
                        else if(BtnSiguienteSpt.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            Escena = Escena+1;
                            while (lista->puntaje.empty() == false) {
                                lista->puntaje.pop();
                            }
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
                            nivel->casillas[lista->fila()][lista->columna()]->sprite.setTexture(nivel->getTexturaPersonajeFrente());
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
                            nivel->casillas[lista->fila()][lista->columna()]->sprite.setTexture(nivel->getTexturaPersonajeIzquierda());
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
                            nivel->casillas[lista->fila()][lista->columna()]->sprite.setTexture(nivel->getTexturaPersonajeDerecha());
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
    CargaGrafica CargaFondoMenu = CargaGrafica("imagenes/MenuFondo.jpg", 0, 0, 1, 1, FondoMenuTx, FondoMenuSpt,0);
    CargaGrafica CargaLogo = CargaGrafica("imagenes/logoSokoban.png",405,100,0.65,0.65, LogoTx, LogoSpt,1);
    CargaGrafica CargaBtnJugar = CargaGrafica("imagenes/btnJugar.png", 400, 390, 0.9, 0.9, BtnJugarTx, BtnJugarSpt,1);
    CargaGrafica CargaBtnCargar = CargaGrafica("imagenes/btnCargarPartida.png", 400, 510, 0.9, 0.9, BtnCargarPartidaTx, BtnCargarPartidaSpt, 1);
    CargaGrafica CargaBtnSalir = CargaGrafica("imagenes/btnSalir.png", 400, 630, 0.9, 0.9, BtnSalirTx, BtnSalirSpt, 1);
    CargaGrafica CargaBtnNivel1 = CargaGrafica("imagenes/btnNivel1.png", 160, 300, 0.75, 0.75, BtnNivel1Tx, BtnNivel1Spt, 1);
    CargaGrafica CargaBtnNivel2 = CargaGrafica("imagenes/btnNivel2.png", 360, 500, 0.75, 0.75, BtnNivel2Tx, BtnNivel2Spt, 1);
    CargaGrafica CargaBtnNivel3 = CargaGrafica("imagenes/btnNivel3.png", 560, 300, 0.75, 0.75, BtnNivel3Tx, BtnNivel3Spt, 1);
    CargaGrafica CargaBtnNivel4 = CargaGrafica("imagenes/btnNivel4.png", 760, 500, 0.75, 0.75, BtnNivel4Tx, BtnNivel4Spt, 1);
    CargaGrafica CargaBtnNivel5 = CargaGrafica("imagenes/btnNivel5.png", 960, 300, 0.75, 0.75, BtnNivel5Tx, BtnNivel5Spt, 1);
    CargaGrafica CargaBtnDelvolverS = CargaGrafica("imagenes/btnDevolverS.png", 80, 800, 0.50, 0.65, BtnDevolverSTx, BtnDevolverSSpt, 1);
    CargaGrafica CargaBtnReiniciar = CargaGrafica("imagenes/btnReiniciar.png", 1050, 200, 0.35, 0.35, BtnReiniciarTx, BtnReiniciarSpt, 1);
    CargaGrafica CargaBtnHome = CargaGrafica("imagenes/btnHome.png", 1060, 310, 0.68, 0.7, BtnHomeTx, BtnHomeSpt, 1);
    CargaGrafica CargaBtnNiveles = CargaGrafica("imagenes/btnNiveles.png", 1070, 410, 0.68, 0.7, BtnNivelesTx, BtnNivelesSpt, 1);
    CargaGrafica CargaBtnRepeticion = CargaGrafica("imagenes/btnRepeticion.png", 450, 360, 0.68, 0.7, BtnRepeticionTx, BtnRepeticionSpt, 1);
    CargaGrafica CargaBtnSiguiente = CargaGrafica("imagenes/btnSiguiente.png", 650, 365, 0.68, 0.7, BtnSiguienteTx, BtnSiguienteSpt, 1);
    CargaGrafica CargaBarraVictoria = CargaGrafica("imagenes/BarraVictoria.png", 300, 350, 0.35, 0.35, BarraVictoriaTx, BarraVictoriaSpt, 1);
    CargaGrafica CargaFondoNivel1 = CargaGrafica("imagenes/fondo1.jpg", 0, 0, 2.5, 2.5, FondoNivel1Tx, FondoNivel1Spt, 0);
    CargaGrafica CargaFondoNivel2 = CargaGrafica("imagenes/fondo2.png", 0, 0, 2.3, 2.3, FondoNivel2Tx, FondoNivel2Spt, 0);
    CargaGrafica CargaFondoNivel3 = CargaGrafica("imagenes/fondo3.jpg", 0, 0, 3.3, 3.3, FondoNivel3Tx, FondoNivel3Spt, 0);
    CargaGrafica CargaFondoNivel4 = CargaGrafica("imagenes/fondo4.png", 0, 0, 2, 2, FondoNivel4Tx, FondoNivel4Spt, 0);
    
}
void Juego::CargarSonidos() {
 
    MusicaInicial.openFromFile("sonidos/Musica_Inicio.wav");
    MusicaInicial.setVolume(15.f);
    MusicaInicial.setLoop(true);
    
    MusicaSelector.openFromFile("sonidos/Selector_Niveles.wav");
    MusicaSelector.setVolume(15.f);
    MusicaSelector.setLoop(true); 

    MusicaNivel1.openFromFile("sonidos/Nivel_frio.wav");
    MusicaNivel1.setVolume(15.f);
    MusicaNivel1.setLoop(true);
    
    MusicaNivel2.openFromFile("sonidos/Nivel_agua.wav");
    MusicaNivel2.setVolume(15.f);
    MusicaNivel2.setLoop(true);
    
    MusicaNivel3.openFromFile("sonidos/Nivel_Planta.wav");
    MusicaNivel3.setVolume(15.f);
    MusicaNivel3.setLoop(true);
    
    MusicaNivel4.openFromFile("sonidos/Nivel_Lava.wav");
    MusicaNivel4.setVolume(15.f);
    MusicaNivel4.setLoop(true);
}
void Juego::CargaEscenas() {

    if (Escena == 0) {

        if (!Inicio) {
            MusicaInicial.play();
            MusicaSelector.stop();
            MusicaNivel1.stop();
            MusicaNivel2.stop();
            MusicaNivel3.stop();
            MusicaNivel4.stop();
            Inicio = true;
        }

        window.clear();
        window.draw(FondoMenuSpt);
        window.draw(LogoSpt);
        window.draw(BtnJugarSpt);
        window.draw(BtnCargarPartidaSpt);
        window.draw(BtnSalirSpt);
        window.display();
    }
    if (Escena == 1) {

        if (!Inicio) {
            MusicaInicial.stop();
            MusicaSelector.play();
            MusicaNivel1.stop();
            MusicaNivel2.stop();
            MusicaNivel3.stop();
            MusicaNivel4.stop();
            Inicio = true;
        }

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
        window.clear();

        if (Escena == 2) {

            window.draw(FondoNivel1Spt);

            if (!Inicio) {
                MusicaSelector.stop();
                MusicaNivel1.play();

                nivel = new Nivel(1);
                CargarLista();
                CargaGrafica CargaMeta1 = CargaGrafica("imagenes/Meta1.png", 300, 420, 0.15, 0.15, Meta1Tx, Meta1Spt, 1);
                CargaGrafica CargaMeta2 = CargaGrafica("imagenes/Meta1.png", 840, 540, 0.15, 0.15, Meta2Tx, Meta2Spt, 1);
                CargaGrafica CargaMeta3 = CargaGrafica("imagenes/Meta1.png", 720, 240, 0.15, 0.15, Meta3Tx, Meta3Spt, 1);
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
            if (lista->puntaje.size() == 3) {
                window.draw(BarraVictoriaSpt);
                window.draw(BtnRepeticionSpt);
                window.draw(BtnSiguienteSpt);
            }
        }

        if (Escena == 3) {

            window.draw(FondoNivel2Spt);

            if (!Inicio) {
                MusicaSelector.stop();
                MusicaNivel1.stop();
                MusicaNivel2.play();

                nivel = new Nivel(2);
                CargarLista();
                CargaGrafica CargaMeta1 = CargaGrafica("imagenes/Meta1.png", 600, 240, 0.15, 0.15, Meta1Tx, Meta1Spt, 1);
                CargaGrafica CargaMeta2 = CargaGrafica("imagenes/Meta1.png", 660, 240, 0.15, 0.15, Meta2Tx, Meta2Spt, 1);
                CargaGrafica CargaMeta3 = CargaGrafica("imagenes/Meta1.png", 720, 240, 0.15, 0.15, Meta3Tx, Meta3Spt, 1);
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
            if (lista->puntaje.size() == 3) {
                window.draw(BarraVictoriaSpt);
                window.draw(BtnRepeticionSpt);
                window.draw(BtnSiguienteSpt);
            }
        }
        if (Escena == 4) {

            window.draw(FondoNivel3Spt);

            if (!Inicio) {
                MusicaSelector.stop();
                MusicaNivel2.stop();
                MusicaNivel3.play();

                nivel = new Nivel(3);
                CargarLista();
                lista->puntaje.push(1);
                CargaGrafica CargaMeta1 = CargaGrafica("imagenes/Meta1.png", 420, 300, 0.15, 0.15, Meta1Tx, Meta1Spt, 1);
                CargaGrafica CargaMeta2 = CargaGrafica("imagenes/Meta1.png", 420, 420, 0.15, 0.15, Meta2Tx, Meta2Spt, 1);
                CargaGrafica CargaMeta3 = CargaGrafica("imagenes/Meta1.png", 660, 360, 0.15, 0.15, Meta3Tx, Meta3Spt, 1);
                CargaGrafica CargaMeta4 = CargaGrafica("imagenes/Meta1.png", 600, 480, 0.15, 0.15, Meta4Tx, Meta4Spt, 1);
                CargaGrafica CargaMeta5 = CargaGrafica("imagenes/Meta1.png", 540, 540, 0.15, 0.15, Meta5Tx, Meta5Spt, 1);
                CargaGrafica CargaMeta6 = CargaGrafica("imagenes/Meta1.png", 600, 600, 0.15, 0.15, Meta6Tx, Meta6Spt, 1);
                CargaGrafica CargaMeta7 = CargaGrafica("imagenes/Meta1.png", 720, 540, 0.15, 0.15, Meta7Tx, Meta7Spt, 1);
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
            if (lista->puntaje.size() == 7) {
                window.draw(BarraVictoriaSpt);
                window.draw(BtnRepeticionSpt);
                window.draw(BtnSiguienteSpt);
            }
        }
        if (Escena == 5) {

            window.draw(FondoNivel4Spt);

            if (!Inicio) {
                MusicaSelector.stop();
                MusicaNivel3.stop();
                MusicaNivel4.play();

                nivel = new Nivel(4);
                CargarLista();
                CargaGrafica CargaMeta1 = CargaGrafica("imagenes/Meta1.png", 540, 300, 0.15, 0.15, Meta1Tx, Meta1Spt, 1);
                CargaGrafica CargaMeta2 = CargaGrafica("imagenes/Meta1.png", 540, 360, 0.15, 0.15, Meta2Tx, Meta2Spt, 1);
                CargaGrafica CargaMeta3 = CargaGrafica("imagenes/Meta1.png", 540, 420, 0.15, 0.15, Meta3Tx, Meta3Spt, 1);
                CargaGrafica CargaMeta4 = CargaGrafica("imagenes/Meta1.png", 540, 480, 0.15, 0.15, Meta4Tx, Meta4Spt, 1);
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
            if (lista->puntaje.size() == 4) {
                window.draw(BarraVictoriaSpt);
                window.draw(BtnRepeticionSpt);
                window.draw(BtnSiguienteSpt);
            }
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

