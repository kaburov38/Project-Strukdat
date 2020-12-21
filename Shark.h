#pragma once
#include<SFML/Graphics.hpp>
#include<fstream>
#include "Definition.h"
#include "Animation.h"
#include <time.h>
#include <string>
class Shark
{
private:
	std::string word;
	sf::Sprite body; //shark
	sf::Text text;
	int lives;
	float datatime = 0;
	sf::Clock clock;
	Animation animation;
public:
	Shark();
	Shark(sf::Texture& _texture, sf::Font& font, std::string str,int _lives,int y);
	void Init(sf::Texture& _texture, sf::Font& font, std::string str, int _lives,int y);
	void Update();
	void Draw(sf::RenderWindow& _window);
	std::string getString();
};