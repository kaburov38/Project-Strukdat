#include "linkedlist.h"

linkedlist::linkedlist()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

void linkedlist::addvalue(string hiupura2)
{
	Node* temp = new Node(hiupura2);
	if (size == 0) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
	tail->next = head;
	size++;
}

void linkedlist::viewValue()
{
	Node* iterator = new Node("cuma iterator");
	iterator = head;
	while (iterator) {
		cout << "[" << iterator->hiupura2 << "] ";
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
	Node* last = NULL;
	Node* iterator = new Node("cuma iterator");
	iterator = head;
	for (int i = 0; i < index; i++) {
		last = iterator;
		iterator = iterator->next;
	}
	last->next = iterator->next;
	delete iterator;
}

bool linkedlist::searchWord(string word)
{
	Node* iterator = new Node("cuma iterator");
	iterator = head;
	for (int i = 0; i < size; i++) {
		if (iterator->hiupura2 == word)
		{
			return true;
		}
		iterator = iterator->next;
	}
	return false;
	delete iterator;
}
