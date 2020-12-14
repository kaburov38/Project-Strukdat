#pragma once
#include<SFML/Graphics.hpp>
#include "Definition.h"
#include "State.h"
#include "MainMenuState.h"
#include "Animation.h"
class GameState : public State
{
public:
	GameState();
	~GameState();

	void Init(sf::RenderWindow& _window);
	void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state);
	void Update(sf::RenderWindow& _window, std::vector<State*>& _state);
	void Draw(sf::RenderWindow& _window);
private:
	sf::Texture _texture, _hiu1;
	sf::Sprite _sprite, _hiu;
	sf::Clock _clock;
	Animation anim;
	float deltatime = 0;
	sf::Clock _animationtimer;
	sf::Font _font;
	sf::Text _string;
};

