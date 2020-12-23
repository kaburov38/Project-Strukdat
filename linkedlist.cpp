#include "linkedlist.h"

linkedlist::linkedlist()
{
	head = NULL;
	tail = NULL;
	size = 0;
	if (!sharkdies_sb.loadFromFile(Shark_Dies))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_sharkdies.setBuffer(sharkdies_sb);
	_sharkdies.setVolume(25);
	if (!sharkhit_sb.loadFromFile(Shark_Hit))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_sharkhit.setBuffer(sharkhit_sb);
	_sharkhit.setVolume(25);
}

void linkedlist::addvalue(sf::Texture& _texture, sf::Font& font, std::string str, int _lives, int y)
{
	Node* temp = new Node(_texture, font, str, _lives, y);
	if (size == 0) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
	size++;
}

void linkedlist::viewValue()
{
	Node* iterator = head;
	while (iterator) {
		cout << "[" << iterator->hiu.getString() << "] ";
		iterator = iterator->next;
	}
	cout << endl;
}

void linkedlist::deleteIndex(int index)
{
	if (index >= size) {
		cout << "Index too big" << endl;
		return;
	}
	if (index == 0)
	{
		Node* temp = head;
		head = temp->next;
		delete temp;
		size--;
	}
	else
	{
		Node* iterator = head;
		for (int i = 0; i < index - 1; i++) {
			iterator = iterator->next;
		}
		if (index == size - 1)
		{			
			tail = iterator;
			iterator = iterator->next;
			tail->next = NULL;
		}
		else
		{
			Node* temp = iterator;
			iterator = iterator->next;
			temp->next = iterator->next;
		}
		delete iterator;
		size--;
	}
	
}

int linkedlist::searchWord(string word)
{
	Node* iterator = head;
	for (int i = 0; i < size; i++) {
		if (iterator->hiu.getString() == word)
		{
			return i;
		}
		iterator = iterator->next;
	}
	return -1;
}

void linkedlist::Update()
{
	Node* iterator = head;
	for (int i = 0; i < size; i++) {
		iterator->hiu.Update();
		if (iterator->hiu.isDeath())
		{
			deleteIndex(i);
			iterator = head;
			i = -1;
		}
		else
		{
			iterator = iterator->next;
		}		
	}
	std::cout << '\n';
}
void linkedlist::Draw(sf::RenderWindow& _window)
{
	Node* iterator = head;
	for (int i = 0; i < size; i++) {
		iterator->hiu.Draw(_window);
		iterator = iterator->next;
	}
}
int linkedlist::getSize()
{
	return size;
}
void linkedlist::Randomize()
{
	Node* iterator = head;
	for (int i = 0; i < size; i++) 
	{
		std::string temp;
		do {
			temp = getSharkString();
			iterator->hiu.setString(temp);
		} while (searchWord(temp) == -1);
		iterator = iterator->next;
	}
}
Shark& linkedlist::getShark(int index)
{
	Node* iterator = head;
	for (int i = 0; i < index - 1; i++) {
		iterator = iterator->next;
	}
	return iterator->hiu;
}
void linkedlist::reduceLives(int index)
{
	Node* iterator = head;
	for (int i = 0; i < index - 1; i++) {
		iterator = iterator->next;
	}
	iterator->hiu.reduceLives();
}
bool linkedlist::Attack(std::string word, sf::Texture& _boneshark1, sf::Texture& _boneshark2)
{
	Node* iterator = head;
	for (int i = 0; i < size; i++) {
		if (iterator->hiu.getString() == word)
		{
			iterator->hiu.reduceLives();
			if (iterator->hiu.getLives() <= 0)
			{
				_sharkdies.play();
				if (iterator->hiu.getType() == 1)
				{
					iterator->hiu.death(_boneshark1);
				}
				else
				{
					iterator->hiu.death(_boneshark2);
				}
				return true;
			}
			else
			{
				_sharkhit.play();
				std::string temp;
				do {
					temp = getSharkString();
					iterator->hiu.setString(temp);
				} while (searchWord(temp) == -1);
				return true;
			}
		}
		iterator = iterator->next;
	}
	return false;
}
bool linkedlist::isGameOver()
{
	Node* iterator = head;
	for (int i = 0; i < size; i++)
	{
		if (iterator->hiu.GetSprite().getPosition().x <= 0)
			return true;
	}
	return false;
}