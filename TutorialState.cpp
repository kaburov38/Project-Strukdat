#include "TutorialState.h"
#include<iostream>

TutorialState::TutorialState()
{

}

TutorialState::~TutorialState()
{

}

void TutorialState::Init(sf::RenderWindow& _window)
{
	if (!_texture.loadFromFile(Tutorial_BG))
	{
		std::cout << "Failed To Open File" << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setScale(_window.getSize().x / _sprite.getGlobalBounds().width, _window.getSize().y / _sprite.getGlobalBounds().height);

	if (!_font.loadFromFile(Main_Menu_Font_Filepath))
	{
		std::cout << "Failed To Open File" << std::endl;
	}
	_back.setFont(_font);
	_back.setString("Main Menu");
	_back.setCharacterSize(42);
	_back.setFillColor(sf::Color(255, 255, 255, 255));
	_back.setOutlineThickness(3);
	_back.setOutlineColor(sf::Color::Black);
	_back.setPosition((_window.getSize().x / 2) - (_back.getGlobalBounds().width / 2), _window.getSize().y - 3 * (_back.getGlobalBounds().height / 2));
}

void TutorialState::Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == _event.Closed)
		{
			_window.close();
		}
		if (IsTextHovered(_back, _window))
		{
			_back.setFillColor(sf::Color(255, 255, 255, 150));
		}
		else
		{
			_back.setFillColor(sf::Color(255, 255, 255, 255));
		}
		if (IsTextClicked(_back, sf::Mouse::Left, _window))
		{
			_state.push_back(new MainMenuState);
			_state.back()->Init(_window);
		}
	}
}

void TutorialState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{

}

void TutorialState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_sprite);
	_window.draw(_back);
	_window.display();
}
