#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<fstream>
#include "Definition.h"
#include "State.h"
#include "MainMenuState.h"
class GameOverState : public State
{
public:
	GameOverState(int score);
	~GameOverState();

	void Init(sf::RenderWindow& _window);
	void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state);
	void Update(sf::RenderWindow& _window, std::vector<State*>& _state);
	void Draw(sf::RenderWindow& _window);
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	int _score;
	sf::Font _font;
	sf::Text _scoretext, _gameover,_back, _highscore; 
	sf::Music _music;
};

