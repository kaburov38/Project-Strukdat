#include "player.h"

player::player()
{
	deltatime = 0.f;
	Playertex.loadFromFile(Player_Sprite_Texture_Filepath);
	body.setTexture(Playertex);
	body.setScale(sf::Vector2f(1.5f, 1.5f));
	playeranim.Init(&Playertex, sf::Vector2u(8, 1), 0.2f);
}

void player::update()
{
	deltatime = playerclock.restart().asSeconds();
	playeranim.Update(0, deltatime);
	body.setTextureRect(playeranim.uvRect);
}

void player::setpos(float x, float y)
{
	body.setPosition(sf::Vector2f(x, y));

}

void player::draw(sf::RenderWindow& _windows)
{
	_windows.draw(body);
}

