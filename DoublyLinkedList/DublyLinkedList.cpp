#include "DublyLinkedList.h"
#include "Node.h"
using namespace std;

DublyLinkedList::DublyLinkedList() {
	head = nullptr;
	tail = nullptr;

}

bool DublyLinkedList::add(Node* n, int pos) {
		if (n == nullptr) {//checks for error
			return false;
		}
		if (pos > size()) {
			return false;
		}
		//if we are adding the first node into an empty DLL
		if (size() == 0) {
			head = n;
			tail = n;
			n->setPrev(nullptr);

			n->setNext(nullptr);
			
		}
		else if (pos == size()) {
			n->setNext(nullptr);
			n->setPrev(tail);
			tail->setNext(n);
			tail = n;
			
		}
		else{
			//gets the pointer for the node to add in front
			Node* newNode = nodeAt(pos);
			Node* newNodePrev = newNode->getPrev();

			
			n->setNext(newNode);//sets the next-pointer for the node we are adding
			n->setPrev(newNodePrev);//sets the prev-pointer for the node we are adding
			newNodePrev->setNext(n);//changes the previous nodes next-pointer to point at the node we are adding
			newNode->setPrev(n);//changes the next nodes prev-pointer to point at the node we are adding
			
		}
		return true;
}

void DublyLinkedList::display_forward() {
	Node* n;
	n = head;
	while (n != nullptr) {
		cout << n->getData() << " <==> ";
		n = n->getNext();
	}
	cout << endl;
}

void DublyLinkedList::display_backwards() {
	Node* n;
	n = tail;
	while (n != nullptr) {
		cout << n->getData() << " <==> ";
		n = n->getPrev();
	}
	cout << endl;
}

//returns amount of nodes in the line
int DublyLinkedList::size() {
	Node* n;
	n = head;
	int i = 0;
	while (n != nullptr) {
		n = n->getNext();
		i += 1;
	}

	return i;
}

int DublyLinkedList::search(Node* data) {
	Node* n;
	n = head;
	int i = 0;
	while (n != data) {
		if (n == tail) {
			return  -1;
		}
		n = n->getNext();
		i += 1;
	}
	return i;
}
Node* DublyLinkedList::nodeAt(int pos) {
	Node* n;
	n = head;
	int i = 0;
	while (i < pos) {
		if (n == tail) {
			return  nullptr;
		}
		n = n->getNext();
		i ++;
	}
	return n;
}

bool DublyLinkedList::remove(int pos) {

	Node* n;
	n = head;
	int i = 1;
	while (i<pos) {
		
		if (n == tail) {
			return false;
			
		}
		n=n->getNext();
		i++;
	}

	n = nodeAt(pos);
	if (n->getPrev() == nullptr) {
		head = n->getNext();
		head->setPrev(nullptr);
	}
	else if (n->getNext() == nullptr) {
		tail = n->getPrev();
		tail->setNext(nullptr);
	}
	else {
		n->getPrev()->setNext(n->getNext());
		n->getNext()->setPrev(n->getPrev());
	}
	delete(n);
	return true;

}
bool DublyLinkedList::replace(Node* oldNode, Node* newNode) {
	//checks for error
	Node* n;
	n = head;
	if (newNode == nullptr||oldNode==nullptr) {
		return false;
	}

	while (n != oldNode) {
		
		if (n == tail) {
			return false;

		}
		n=n->getNext();
	}

	//replaces all the connections between the old one to the new one when i replace the head
	if(oldNode == head){
		newNode->setPrev(nullptr);
		newNode->setNext(oldNode->getNext());
		oldNode->getNext()->setPrev(newNode);
		head = newNode;
	}
	//when i replace the tail 
	else if (oldNode == tail) {
		newNode->setNext(nullptr);
		newNode->setPrev(oldNode->getPrev());
		oldNode->getPrev()->setNext(newNode);
		tail = newNode;
	}
	else{
		oldNode->getPrev()->setNext(newNode);
		oldNode->getNext()->setPrev(newNode);
		newNode->setPrev(oldNode->getPrev());
		newNode->setNext(oldNode->getNext());
	}
	delete(oldNode);
	return true;
}