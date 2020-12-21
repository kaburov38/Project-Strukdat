#include "GameState.h"
#include<iostream>
GameState::GameState()
{
}

GameState::~GameState()
{
}

void GameState::Init(sf::RenderWindow& _window)
{
	if (!_texture.loadFromFile(Game_State_BG_Filepath))
	{
		std::cout << "Failed To Open File" << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setScale(_window.getSize().x / _sprite.getGlobalBounds().width, _window.getSize().y / _sprite.getGlobalBounds().height);
	_clock.restart();

	if (!_hiu1.loadFromFile(Enemy_1_Sprite_Texture_Filepath))
	{
		std::cout << "Failed To Open File" << std::endl;
	}
	if (!_font.loadFromFile(Main_Menu_Font_Filepath)) {
		std::cout << "Failed To Open File" << std::endl;
	}
	hiu.Init(_hiu1,_font,"abcdefhsa",1,1);
	hiuu.Init(_hiu1, _font, "xxxxxxx", 1, 2);
}

void GameState::Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == _event.Closed)
		{
			_window.close();
		}
	}
}

void GameState::Update(sf::RenderWindow& _window, std::vector<State*>& _state) {
	hiu.Update();
	hiuu.Update();
}

void GameState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_sprite);
	hiu.Draw(_window);
	hiuu.Draw(_window);
	_window.display();
}
