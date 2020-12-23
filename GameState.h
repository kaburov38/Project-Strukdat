#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
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
	sf::Texture _texture, _hiu1, _hiu2, _bone1, _bone2;
	sf::Sprite _sprite;
	sf::Clock _clock;
	Animation anim;
	float deltatime = 0;
	sf::Clock _animationtimer, _cooldown, _spawner, _gameoverclock;
	sf::Font _font;
	sf::Text input_text, point_txt, _gameovertext;
	linkedlist sharks;
	std::string input_str;
	player diver;
	int point;
	bool isgameover;
	sf::Music _music;
	sf::SoundBuffer playerdies_sb, wrong_sb;
	sf::Sound _playerdies, _wrong;
};

