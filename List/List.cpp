// 2013.11.05

#include <cstdlib>
#include "define.h"
#include "List.h"
#include "Node.h"

// constructor of list and let it empty by set head to NULL
template <class List_entry>
List<List_entry>::List() {
    head = NULL;
}

// when the object was destroyed, clear the list
template <class List_entry>
List<List_entry>::~List() {
    clear();
}

/* this the copy constructor, copy the copy_one list
 * to a new one, and let this->head points to the 
 * copy one 
 */
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
/*
 * this the overloading the equal operator
 * copy the copy_one list to a new one
 * delete the original, let the head points
 * the new one
*/
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

// calculate the size of the list, return the result
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

// clear the list, using a iterator pt through the list
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

// traverse the list, through the list
template <class List_entry>
void List<List_entry>::traverse(void(*visit)(List_entry &x)) {
    Node<List_entry> *pt;
    for (pt = head; pt != NULL; pt = pt->next)
	(*visit)(pt->entry);
}

// if the position is valid and list in not empty, return the value
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

// if the position is valid and list in not empty, replace the value
// of the position
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

// if the position is valid and list is not empty, delete the node at the
// position
template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x) {
    
    if (position < 0 || position > this->size())
	return range_error;
    if (empty())
	return underflow;

    Node<List_entry> *last, *pt;
    // when position = 0, since last points to the first node
    // we do not have to handle it along
    last = set_position(position -1);
    pt = set_position(position);

	
	
    last->next = pt->next;
    delete pt;

}

// if the position is valid, creat a new node with value x, and insert
// in the list at position
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x) {
    if (position < 0 || position > this->size())
	return range_error;
    
    Node<List_entry> *new_node, *follow, *pre;

    // when insert the value in the middle or at the end
    if (position > 0) {
	pre = set_position(position - 1);
	follow = pre->next;
    } else // firstly insert and insert at head
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

// Finding the position in the list, return a pointer points to it
// if the position is 0, return the head
template <class List_entry>
Node<List_entry> *List<List_entry>::set_position(int position) const {
    Node<List_entry> *ptr = NULL;
    
    // when the position is 0, return the pointer points the head
    ptr = this->head;
    for (int i = 0; i < position; i++)
	ptr = ptr->next;
	
    return ptr;
}
