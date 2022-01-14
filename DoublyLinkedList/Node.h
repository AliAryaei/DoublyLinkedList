#pragma once
#include <iostream>
using namespace std;

class Node {
private:
	int data;
	Node* next = nullptr;
	Node* prev = nullptr;
public:
	Node(int);
	int getData();
	void setData(int );

	Node* getNext();
	void setNext(Node* );

	Node* getPrev();
	void setPrev(Node* );
};
