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
	_hiu.setTexture(_hiu1);
	_hiu.setScale(2, 2);
	anim.Init(&_hiu1, sf::Vector2u(20, 1), 0.1f);	
	if (!_font.loadFromFile(Main_Menu_Font_Filepath))
	{
		std::cout << "Failed to Open Font" << std::endl;
	}
	_string.setFont(_font);
	_string.setString("Typer Shark");
	_string.setCharacterSize(22);
	_string.setFillColor(sf::Color(255, 255, 255, 255));
	_string.setOutlineThickness(1);
	_string.setOutlineColor(sf::Color::Black);
	std::cout << _hiu.getGlobalBounds().width / 20 << " " << _hiu.getGlobalBounds().height;
	_string.setPosition(_hiu.getPosition().x + _hiu.getGlobalBounds().width / 80, _hiu.getPosition().y + _hiu.getGlobalBounds().height / 2.75);
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

void GameState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{
	deltatime = _animationtimer.restart().asSeconds();
	anim.Update(0, deltatime);
	_hiu.setTextureRect(anim.uvRect);
}

void GameState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_sprite);
	_window.draw(_hiu);
	_window.draw(_string);
	_window.display();
}
