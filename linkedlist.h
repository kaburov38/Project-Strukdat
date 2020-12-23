#pragma once
#include <iostream>
#include "shark.h"
#include "Additional.h"
using namespace std;

struct Node
{
	Shark hiu;
	Node* next;
	Node(sf::Texture& _texture, sf::Font& font, std::string str, int _lives, int y) {
		hiu.Init(_texture, font, str, _lives, y);
		next = NULL;
	}
	Node() {
		next = NULL;
	}
};

class linkedlist
{
public:
	linkedlist();
	void addvalue(sf::Texture& _texture, sf::Font& font, std::string str, int _lives, int y);
	void viewValue();
	void deleteIndex(int index);
	int searchWord(string word);
	void Update();
	void Draw(sf::RenderWindow& _window);
	int getSize();
	void Randomize();
	Shark getShark(int index);
	void reduceLives(int index);
	bool Attack(std::string word);
	bool isGameOver();

private:
	Node* head;
	Node* tail;
	int size;
};

