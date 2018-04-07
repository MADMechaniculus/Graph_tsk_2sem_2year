#pragma once
#include <iostream>
#include <deque>

struct  element
{ 
	deque<int> myDeq(int(10));
	element *Next;
};

class MyOwnList
{
	element *Head;

public:
	MyOwnList() { Head = nullptr; }
	~MyOwnList();
	void Add(deque<int> x);
	void Show();
};

MyOwnList::~MyOwnList()
{
	element *temp = Head->Next;
	delete Head;
	Head = temp;
}

void MyOwnList::Add(deque<int> x) {
	element *temp = new element;
	temp->x = x;
	temp->Next = Head;
	Head = temp;
}

void MyOwnList::Show() {
	element *temp = Head;

	while (temp != nullptr) {
		std::cout << temp->x << " ";
		temp = temp->Next;
	}
}