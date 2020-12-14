#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u ImageCount, float Switchtime);
	Animation();
	void Init(sf::Texture* texture, sf::Vector2u ImageCount, float Switchtime);
	~Animation();
	void Update(int row, float deltaTime);

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u ImageCount;
	sf::Vector2u CurrentImage;
	float totalTime;
	float SwitchTime;
};

