// 2013.10.08

#ifndef DEFINE_H
#define DEFINE_H
#include <stdlib.h>
typedef int Queue_entry;
enum Error_code{success, underflow, overflow};

struct Node {
	Queue_entry entry;
	Node *next;

	Node() {
		next = NULL;
	};
	Node(Queue_entry item, Node *add_on = NULL) {
		next = add_on;
		entry= item;
	};
};
#endif
