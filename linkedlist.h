#pragma once
#include <iostream>
using namespace std;

struct Node
{
	string hiupura2;
	Node* next;
	Node(string hiupura2 = "") {
		this->hiupura2 = hiupura2;
	}

};

class linkedlist
{
	linkedlist();
	void addvalue(string hiupura2/*hiu*/);
	void viewValue();
	void deleteIndex(int index);
	bool searchWord(string word);

private:
	Node* head;
	Node* tail;
	int size;
};

