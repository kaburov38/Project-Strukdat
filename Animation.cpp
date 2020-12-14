#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u ImageCount, float Switchtime)
{
	this->ImageCount = ImageCount;
	this->SwitchTime = Switchtime;
	totalTime = 0.0f;
	CurrentImage.x = 0;
	uvRect.width = texture->getSize().x / float(ImageCount.x);
	uvRect.height = texture->getSize().y / float(ImageCount.y);
}
Animation::Animation()
{

}
Animation::~Animation(){

}
void Animation::Init(sf::Texture* texture, sf::Vector2u ImageCount, float Switchtime)
{
	this->ImageCount = ImageCount;
	this->SwitchTime = Switchtime;
	totalTime = 0.0f;
	CurrentImage.x = 0;
	uvRect.width = texture->getSize().x / float(ImageCount.x);
	uvRect.height = texture->getSize().y / float(ImageCount.y);
}
void Animation::Update(int row, float deltaTime)
{
	CurrentImage.y = row;
	totalTime += deltaTime;
	if (totalTime >= SwitchTime)
	{
		totalTime -= SwitchTime;
		CurrentImage.x++;

		if (CurrentImage.x >= ImageCount.x)
		{
			CurrentImage.x = 0;
		}
	}
	uvRect.left = CurrentImage.x * uvRect.width;
	uvRect.top = CurrentImage.y * uvRect.height;
}
