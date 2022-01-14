#pragma once
#include <iostream>


class Node;
class DublyLinkedList;
class DublyLinkedList {
private:
	Node* head;
	Node* tail;

public:
	DublyLinkedList();
	bool add(Node* n, int pos);
	bool remove(int pos);
	bool replace(Node* old_, Node* new_);
	int search(Node* data);
	Node* nodeAt(int pos);
	void display_forward();
	void display_backwards();
	int size();
};