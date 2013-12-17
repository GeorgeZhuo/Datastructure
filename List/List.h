// 2013.11.05
// the prototype of List completement by linked list

#ifndef LIST_H
#define LIST_H

#include "define.h"
#include "Node.h"

template <class List_entry>
class List {
public:
	List();
	~List();
	List(const List<List_entry> &copy);
	void operator=(const List<List_entry> &copy);
	int size() const;
	bool empty() const;
	void clear();
	void traverse(void(*visit)(List_entry &));
	void print() const;
	Error_code retrieve(int position, List_entry &x) const;
	Error_code replace(int position, const List_entry &x);
	Error_code remove(int position, List_entry &x);
	Error_code insert(int position, const List_entry &x);

private:
	Node<List_entry> *head;
	Node<List_entry> *set_position(int position) const;
};
#endif
