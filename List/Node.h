// 2013.11.05
// the definition of Node
#ifndef NODE_H
#define NODE_H
#include <cstdlib>

template <class Node_entry>
struct Node {
	Node_entry entry;
	Node<Node_entry> *next;

	Node();
	Node(Node_entry, Node<Node_entry> *link = NULL);
};

template <class Node_entry>
Node<Node_entry>::Node(){
	next = NULL;
}

template <class Node_entry>
Node<Node_entry>::Node(Node_entry x, Node<Node_entry> *link) {
	entry = x;
	next = link;
}
#endif
