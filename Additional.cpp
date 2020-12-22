#include "Additional.h"
#include "Definition.h"

bool IsTextHovered(sf::Text object, sf::RenderWindow& _window)
{
	sf::IntRect temp(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
	if (temp.contains(sf::Mouse::getPosition(_window)))
	{
		return true;
	}
	return false;
}

bool IsSpriteHovered(sf::Sprite object, sf::RenderWindow& _window)
{
	sf::IntRect temp(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
	if (temp.contains(sf::Mouse::getPosition(_window)))
	{
		return true;
	}
	return false;
}
bool IsTextClicked(sf::Text object, sf::Mouse::Button button, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::IntRect temp(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
		if (temp.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}
bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::IntRect temp(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
		if (temp.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}
std::string getSharkString()
{
	std::fstream file;
	std::string word;
	int line;
	line = rand() % 16000 + 1;
	file.open(Word_Bank);
	for (int i = 0; i < line; i++)
	{
		getline(file, word);
	}
	file.close();
	return word;
}
