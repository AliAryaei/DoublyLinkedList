#include <iostream>
#include "DublyLinkedList.h"
#include "Node.h"


Node* n0 = new Node(0);
Node* n1 = new Node(1);
Node* n2 = new Node(2);
Node* n3 = new Node(3);
Node* n4 = new Node(4);

DublyLinkedList list;
int main() {
	list.add(n0, 0);
	list.add(n1, 1);
	list.add(n2, 2);
	list.display_forward();
	list.add(n3, 1);
	list.display_forward();
	list.remove(2);
	list.display_forward();
	list.display_backwards();
	list.search(n3);
	list.replace(n3, n4);
	list.display_forward();
	list.size();
	return 0;
}