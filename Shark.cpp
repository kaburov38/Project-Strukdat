#include "Shark.h"
#include <iostream>
Shark::Shark() {

}

Shark::Shark(sf::Texture& _texture, sf::Font& font, std::string str, int _lives,int y) {
	lives = _lives;
	word = str;
	body.setTexture(_texture);
	animation.Init(&_texture, sf::Vector2u(20, 1), 0.1f);
	body.setPosition(1000, y*body.getGlobalBounds().height);
	text.setFont(font);
	text.setString(word);
	text.setCharacterSize(22);
	text.setFillColor(sf::Color(255, 255, 255, 255));
	text.setOutlineThickness(1);
	text.setOutlineColor(sf::Color::Black);
	text.setPosition(body.getPosition().x + body.getGlobalBounds().width / 2, body.getPosition().y + body.getGlobalBounds().height / 2.75);
}

void Shark::Init(sf::Texture& _texture, sf::Font& font, std::string str, int _lives,int y) {
	lives = _lives;
	word = str;
	body.setTexture(_texture);
	body.setScale(2, 2);
	animation.Init(&_texture, sf::Vector2u(20, 1), 0.1f);
	body.setPosition(1000, y * body.getGlobalBounds().height);
	text.setFont(font);
	text.setString(word);
	text.setCharacterSize(22);
	text.setFillColor(sf::Color(255, 255, 255, 255));
	text.setOutlineThickness(1);
	text.setOutlineColor(sf::Color::Black);
	text.setPosition((body.getPosition().x + body.getGlobalBounds().width / 2) - text.getGlobalBounds().width / 2, body.getPosition().y + body.getGlobalBounds().height / 2.75);
}

void Shark::Update()
{
	datatime = clock.restart().asSeconds();
	animation.Update(0, datatime);
	body.setTextureRect(animation.uvRect);
	body.move(-11*datatime, 0);
	text.setPosition((body.getPosition().x + body.getGlobalBounds().width / 2) - text.getGlobalBounds().width / 2, body.getPosition().y + body.getGlobalBounds().height / 2.75);
	std::cout << text.getPosition().x << " ";
}

void Shark::Draw(sf::RenderWindow& _window) {
	_window.draw(body);
	_window.draw(text);
}