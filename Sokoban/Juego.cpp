#include "pch.h"
#include "Juego.h"

void Juego::CargarJuego() {
   window.create(VideoMode(1200, 700), "Sokoban");
   // Cargartexturas();
    
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
                   

                }
                break;

            case Event::MouseMoved:

                break;
 
            default:
                break;
            }

        }
      //  Victoria();
      //  CargaEscenas();
    }
}

