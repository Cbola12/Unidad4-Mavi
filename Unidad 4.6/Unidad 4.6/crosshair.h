#pragma once
//Bibliotecas//
#include "stdafx.h"

using namespace sf;

class crosshair
{
	Texture tex_cursor;
    Sprite cursor;

public:

	crosshair() {
		//cargamos textura
		tex_cursor.loadFromFile("crosshair.png");
		cursor.setTexture(tex_cursor);
		cursor.setOrigin(tex_cursor.getSize().x / 2.0f, tex_cursor.getSize().y / 2.0f);
		cursor.setScale(0.5f, 0.5f);
		

	}

	void Dibujar(sf::RenderWindow& wnd) {

		wnd.draw(cursor);
		wnd.setMouseCursorVisible(false);
	}

	void Posicionar(float x, float y) {
		cursor.setPosition(x, y);

	}

	Vector2f ObtenerPosicion() {
		return cursor.getPosition();
	}

};

