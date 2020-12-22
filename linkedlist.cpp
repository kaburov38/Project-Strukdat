#include "linkedlist.h"

linkedlist::linkedlist()
{
	head = NULL;
	tail = NULL;
	size = 0;
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
	cout << int(word[0]) << std::endl;
	Node* iterator = head;
	for (int i = 0; i < size; i++) {
		//std::cout << "Word : " << word << " Shark: " << iterator->hiu.getString() << std::endl;
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
		iterator = iterator->next;
	}
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
