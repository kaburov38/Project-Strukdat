#pragma once
#include<SFML/Graphics.hpp>
#include "Definition.h"
#include "State.h"
#include "MainMenuState.h"
#include "linkedlist.h"
#include "Animation.h"
#include "Shark.h"
#include "player.h"
class GameState : public State
{
public:
	GameState();
	~GameState();

	void Init(sf::RenderWindow& _window);
	void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state);
	void Update(sf::RenderWindow& _window, std::vector<State*>& _state);
	void Draw(sf::RenderWindow& _window);
	void SpawnShark(int amount);
private:
	sf::Texture _texture, _hiu1, _hiu2;
	sf::Sprite _sprite;
	sf::Clock _clock;
	Animation anim;
	float deltatime = 0;
	sf::Clock _animationtimer, _cooldown, _spawner;
	sf::Font _font;
	sf::Text _string, input_text, point_txt;
	linkedlist sharks;
	std::string input_str;
	player diver;
	int point;
};

