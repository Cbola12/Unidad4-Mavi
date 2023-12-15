//Bibliotecas//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Juego.h"
#include "stdafx.h"

using namespace sf;


//Entrada//

int main(int argc, char* argv[])
{


	Juego myJuego;
	myJuego.Loop();

	return 0;

}

//Este ejercicio lo hice apoyandome en el video de crosshair, igualmente algunas cosas las hice como en el video y me tiraba errores (ahi tuve que recurrir a chatgpt)