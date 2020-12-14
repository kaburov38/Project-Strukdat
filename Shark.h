#pragma once
#include<SFML/Graphics.hpp>
#include<fstream>
#include "Definition.h"
#include "Animation.h"
class Shark
{
private:
	std::string word;
	sf::Sprite body;
	int lives;
public:
	Shark(sf::Texture _texture, int _lives)
	{

	}
};