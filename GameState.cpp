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
	if (!_hiu2.loadFromFile(Enemy_2_Sprite_Texture_Filepath))
	{
		std::cout << "Failed To Open File" << std::endl;
	}
	if (!_font.loadFromFile(Main_Menu_Font_Filepath)) {
		std::cout << "Failed To Open File" << std::endl;
	}
	SpawnShark(4);
	sharks.viewValue();
	input_str = "";
	input_text.setFont(_font);
	input_text.setString(input_str);
	input_text.setCharacterSize(22);
	input_text.setFillColor(sf::Color(255, 255, 255, 255));
	input_text.setOutlineThickness(1);
	input_text.setOutlineColor(sf::Color::Black);
	//input_text.setPosition((_window.getSize().x / 2) - (input_text.getGlobalBounds().width / 2), _window.getSize().y - input_text.getGlobalBounds().width);
	input_text.setPosition(0, 0);
}

void GameState::Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == _event.Closed)
		{
			_window.close();
		}
		if (_event.type == sf::Event::KeyPressed)
		{
			if (_event.key.code == sf::Keyboard::Enter)
			{
				input_str.erase(std::remove(input_str.begin(), input_str.end(), '\r'), input_str.end());
				if (!sharks.Attack(input_str))
				{
					sharks.Randomize();
				}
				else
				{
					
				}
				input_str = "";
				input_text.setString(input_str);
				std::cout << input_str;
				_cooldown.restart();
				sharks.viewValue();
			}
		}
		if(_event.type == sf::Event::TextEntered)
		{
			if (_event.text.unicode == '\b')
			{
				if (input_str.size() > 0)
				{
					input_str.erase(input_str.size() - 1, 1);
					input_text.setString(input_str);
					input_str.erase(std::remove(input_str.begin(), input_str.end(), '\r'), input_str.end());
				}				
			}
			else
			{
				input_str += toupper(static_cast<char>(_event.text.unicode));
				input_text.setString(input_str);
				input_str.erase(std::remove(input_str.begin(), input_str.end(), '\r'), input_str.end());
			}			
		}
	}
}

void GameState::Update(sf::RenderWindow& _window, std::vector<State*>& _state) {
	if (sharks.isGameOver())
	{
		std::cout << "Game Over" << std::endl;
	}
	if (_cooldown.getElapsedTime().asSeconds() > 10)
	{
		sharks.Randomize();
		_cooldown.restart();
	}
	if (_spawner.getElapsedTime().asSeconds() > 10)
	{
		int amount = rand() % 5;
		SpawnShark(amount);
		_spawner.restart();
	}
	if (sharks.getSize() <= 0)
	{
		SpawnShark(4);
		_spawner.restart();
	}
	sharks.Update();
}

void GameState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_sprite);
	sharks.Draw(_window);
	_window.draw(input_text);
	_window.display();
}

void GameState::SpawnShark(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		std::string temp;
		do {
			int lives = rand() % 2 + 1;
			temp = getSharkString();
			if (lives == 1)
			{
				sharks.addvalue(_hiu1, _font, temp, 1, i);
			}
			else if(lives == 2)
			{
				sharks.addvalue(_hiu2, _font, temp, 2, i);
			}

		} while (sharks.searchWord(temp) == -1);
	}	
}
