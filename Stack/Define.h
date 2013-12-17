// 2013.10.08

#ifndef DEFINE_H
#define DEFINE_H
#include <stdlib.h>
typedef int Stack_entry;
enum Error_code{success, underflow, overflow};

struct Node {
	Stack_entry entry;
	Node *next;

	Node() {
		next = NULL;
	};
	Node(Stack_entry item, Node *add_on = NULL) {
		next = add_on;
		entry= item;
	};
};
#endif
