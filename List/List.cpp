// 2013.11.05

#include <cstdlib>
#include "define.h"
#include "List.h"
#include "Node.h"

template <class List_entry>
List<List_entry>::List() {
    head = NULL;
}

template <class List_entry>
List<List_entry>::~List() {
    clear();
}

template <class List_entry>
List<List_entry>::List(const List<List_entry> &origin) {
    Node<List_entry> *new_head, *tail, *pt, *pt1;
    
    new_head = NULL;
    for (pt = origin.head; pt != NULL; pt = pt->next) {
	pt1 = new Node<List_entry>(pt->entry);
	if (new_head == NULL)
	    new_head = pt1;
	else
	    tail->next = pt1;
	tail = pt1;
    }
    head = new_head;
 
}

template <class List_entry>
void List<List_entry>::operator=(const List<List_entry> &origin) {
    Node<List_entry> *new_head, *tail, *pt, *pt1;
    
    new_head = NULL;
    for (pt = origin.head; pt != NULL; pt = pt->next) {
	pt1 = new Node<List_entry>(pt->entry);
	if (new_head == NULL)
	    new_head = pt1;
	else
	    tail->next = pt1;
	tail = pt1;
    }
    this->clear();
    head = new_head;
}

template <class List_entry> 
int List<List_entry>::size() const {
    int count = 0;

    for (Node<List_entry> *pt = head; pt != NULL; pt = pt->next)
	count++;

    return count;
}

template <class List_entry>
bool List<List_entry>::empty() const {
    return (head == NULL);
}

template <class List_entry>
void List<List_entry>::clear() {
        Node<List_entry> *pt, *pt1;
    pt = pt1 = head;
    for (; pt != NULL; pt = pt->next) {
	pt1 = pt;
	delete pt1;
    }
    head = NULL;
}
template <class List_entry>
void List<List_entry>::traverse(void(*visit)(List_entry &x)) {
    Node<List_entry> *pt;
    for (pt = head; pt != NULL; pt = pt->next)
	(*visit)(pt->entry);
}

template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const {

    if (position < 0 || position > this->size())
	return range_error;
    if (empty())
	return underflow;

    Node<List_entry> *pt = set_position(position);
    x = pt->entry;

    return success;
}

template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x) {
    if (position < 0 || position > this->size())
	return range_error;
    if (empty())
	return underflow;

    Node<List_entry> *pt = set_position(position);
    pt->entry = x;

    return success;
}

template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x) {
    
    if (position < 0 || position > this->size())
	return range_error;
    if (empty())
	return underflow;

    Node<List_entry> *last, *pt;

    last = set_position(position -1);
    pt = set_position(position);

    last->next = pt->next;
    delete pt;

}

template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x) {
    if (position < 0 || position > this->size())
	return range_error;
    
    Node<List_entry> *new_node, *follow, *pre;

    if (position > 0) {
	pre = set_position(position - 1);
	follow = pre->next;
    } else
	follow = head;

    new_node = new Node<List_entry>(x, follow);

    if (new_node == NULL)
	return overflow;
    
    if (position == 0) 
	head = new_node;
    else
	pre->next = new_node;

    return success;
}

template <class List_entry>
Node<List_entry> *List<List_entry>::set_position(int position) const {
    Node<List_entry> *ptr = NULL;

    ptr = this->head;
    for (int i = 0; i < position; i++)
	ptr = ptr->next;
	
    return ptr;
}
