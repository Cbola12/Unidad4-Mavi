#pragma once
#include "stdafx.h"
#include "crosshair.h"
#include "Enemigo.h"

using namespace sf;

class Juego {
	sf::RenderWindow wnd;
	crosshair player;
	Enemigo enemy[5];

	Text puntaje;
	Font fuente;
	int puntos;

	void actualizarPuntaje() {
		//char pts[50];
		puntaje.setString(std::to_string(puntos));
		//puntaje.setString(pts);

	}

public:

	Juego()

		: wnd(sf::VideoMode(800, 600, 32), "Crosshair"),
		player(),
		puntaje(),
		puntos(0)  
	{
		fuente.loadFromFile("arial.ttf");
		puntaje.setFont(fuente);
		puntaje.setPosition(0.0f, 0.0f);
		puntaje.setCharacterSize(50.0f);
		
		
		actualizarPuntaje();
	}
	
	


	void Loop() {

		while (wnd.isOpen()) {
			ProcesarEventos();
			Actualizar();
			Dibujar();

			if (puntos >= 5) {
				wnd.close();
			}

		}
	}

	void ProcesarEventos() {

		Event evt;

		while (wnd.pollEvent(evt)) {
			switch (evt.type) {

			case Event::Closed:
				wnd.close();
				break;
			case Event::MouseMoved:
				player.Posicionar(evt.mouseMove.x, evt.mouseMove.y);
				break;

			case Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Left)
					Disparar();
				break;

			}

		}
	}

	void Actualizar() {

		for (size_t i = 0; i < 5; i++)
		{
			enemy[i].Actualizar(wnd);
		}

		
		
		//Vector2i mousePos = Mouse::getPosition(wnd);
		//player.Posicionar(mousePos.x, mousePos.y);


	}

	void Disparar() {
		//chequeamos colisiones

		Vector2f playerPos = player.ObtenerPosicion();
		for (int i = 0; i < 5; i++) {
			if (enemy[i].activo()) {
				if (enemy[i].Encima(playerPos.x, playerPos.y))
					enemy[i].MuerteEnemy();
				puntos++;
				actualizarPuntaje();
			}
		}

		

	}

	void Dibujar() {

		wnd.clear();

		

		for (int i = 0; i < 5; i++)
		{
			if (enemy[i].activo()) {
				enemy[i].Dibujar(wnd);
			}
		}
		wnd.draw(puntaje);
		player.Dibujar(wnd);
			wnd.display();
	


	}

	

};