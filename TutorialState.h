#pragma once
#include<SFML/Graphics.hpp>
#include "Definition.h"
#include "State.h"
#include "MainMenuState.h"
class TutorialState : public State
{
public:
	TutorialState();
	~TutorialState();

	void Init(sf::RenderWindow& _window);
	void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state);
	void Update(sf::RenderWindow& _window, std::vector<State*>& _state);
	void Draw(sf::RenderWindow& _window);
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Font _font;
	sf::Text _back;
};

