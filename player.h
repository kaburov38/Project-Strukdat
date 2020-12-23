#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "animation.h"
#include "Definition.h"
class player
{
public:
	player();
	void update();
	void setpos(float x, float y);
	void draw(sf::RenderWindow& _windows);
	float getHeight() {
		return body.getGlobalBounds().height;
	}

private:
	sf::Sprite body;
	sf::Texture Playertex;
	Animation playeranim;
	float deltatime;
	sf::Clock playerclock;
};

