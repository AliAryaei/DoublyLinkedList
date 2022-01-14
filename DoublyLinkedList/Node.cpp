#include "Node.h"

Node::Node(int d) {
	data = d;
}

int Node::getData() {
	return data;
}
void Node::setData(int d) {
	data = d;
}

Node* Node::getNext() {
	return next;
}
void Node::setNext(Node* n) {
	next = n;
}

Node* Node::getPrev() {
	return prev;
}
void Node::setPrev(Node* n) {
	prev = n;
}


