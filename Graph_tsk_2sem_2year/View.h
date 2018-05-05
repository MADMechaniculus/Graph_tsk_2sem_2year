#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;

View view;

View viewField(float time) {
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		view.move(0.1*time , 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		view.move(-0.1*time , 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		view.move(0 , -0.1*time);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		view.move(0 , 0.1*time);
	}

	return view;
}