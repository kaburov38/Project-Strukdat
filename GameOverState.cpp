#include "GameOverState.h"
#include<iostream>

GameOverState::GameOverState(int score)
{
	_score = score;
}

GameOverState::~GameOverState()
{
}

void GameOverState::Init(sf::RenderWindow& _window)
{
	if (!_music.openFromFile(Game_Over_Music))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_music.setLoop(true);
	_music.setVolume(30);
	_music.play();
	if (!_texture.loadFromFile(Game_State_BG_Filepath))
	{
		std::cout << "Failed To Open File" << std::endl;
	}
	if (!_font.loadFromFile(Main_Menu_Font_Filepath))
	{
		std::cout << "Failed To Open File" << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setScale(_window.getSize().x / _sprite.getGlobalBounds().width, _window.getSize().y / _sprite.getGlobalBounds().height);

	_gameover.setFont(_font);
	_gameover.setString("Game Over");
	_gameover.setCharacterSize(42);
	_gameover.setFillColor(sf::Color(255, 255, 255, 255));
	_gameover.setOutlineThickness(3);
	_gameover.setOutlineColor(sf::Color::Black);
	_gameover.setPosition((_window.getSize().x / 2) - (_gameover.getGlobalBounds().width / 2), 2 * (_gameover.getGlobalBounds().height / 2));

	_scoretext.setFont(_font);
	_scoretext.setString("Score : " + to_string(_score));
	_scoretext.setCharacterSize(42);
	_scoretext.setFillColor(sf::Color(255, 255, 255, 255));
	_scoretext.setOutlineThickness(3);
	_scoretext.setOutlineColor(sf::Color::Black);
	_scoretext.setPosition((_window.getSize().x / 2) - (_scoretext.getGlobalBounds().width / 2), 6 * (_scoretext.getGlobalBounds().height / 2));
	_gameover.setFont(_font);

	std::ifstream input;
	input.open(Highscore_Filepath, ios::in);
	int highscore;
	input >> highscore;
	if (_score > highscore)
		highscore = _score;
	input.close();
	std::ofstream output;
	output.open(Highscore_Filepath);
	output << highscore;
	output.close();

	_highscore.setFont(_font);
	_highscore.setString("Highscore : " + to_string(highscore));
	_highscore.setCharacterSize(42);
	_highscore.setFillColor(sf::Color(255, 255, 255, 255));
	_highscore.setOutlineThickness(3);
	_highscore.setOutlineColor(sf::Color::Black);
	_highscore.setPosition((_window.getSize().x / 2) - (_highscore.getGlobalBounds().width / 2), 8 * (_highscore.getGlobalBounds().height / 2));

	_back.setFont(_font);
	_back.setString("Main Menu");
	_back.setCharacterSize(42);
	_back.setFillColor(sf::Color(255, 255, 255, 255));
	_back.setOutlineThickness(3);
	_back.setOutlineColor(sf::Color::Black);
	_back.setPosition((_window.getSize().x / 2) - (_back.getGlobalBounds().width / 2), _window.getSize().y - 3 * (_back.getGlobalBounds().height / 2));
}

void GameOverState::Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state)
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
			_music.stop();
			_state.push_back(new MainMenuState);
			_state.back()->Init(_window);
		}
	}
}

void GameOverState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{
	
}

void GameOverState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_sprite);
	_window.draw(_gameover);
	_window.draw(_scoretext);
	_window.draw(_highscore);
	_window.draw(_back);
	_window.display();
}
