// 2013.10.15

#include "Queue.h"
#include "Define.h"

Queue::Queue() {
    font = rear = NULL;
}
Queue::~Queue() {
    clear();
}
Error_code Queue::append(const Queue_entry &item) {
    Node *new_node = new Node(item);

    if (new_node == NULL) return overflow;
    
    if (font == NULL) 
	font = new_node;
    else
	rear->next = new_node;
	
    rear = new_node;
    return success;
}
Error_code Queue::serve() {
    Node *old_node = font;

    if (font == NULL) return underflow;

    font = font->next;
    if ( font == NULL) rear = NULL;
    delete old_node;

    return success;
}

Error_code Queue::retrieve(Queue_entry &item) const {
    if (font == NULL) return underflow;

    item = font->entry;
    return success;
}
bool Queue::empty() const {
    return (font == NULL);
}
Error_code Queue::clear() {
    Node *old_node;
    for (Node *pt = font; pt != NULL; pt = pt->next) {
	old_node = font;
	font = font->next;

	if (font == NULL) rear = NULL;
	delete old_node;
	
    }
}
Queue::Queue(const Queue &origin) {
    Node *new_font, *new_rear, *pt1, *origin_font = origin.font;

    new_font = new_rear = NULL;
    for (Node *pt = origin_font; pt != NULL; pt = pt->next) {
	pt1 = new Node(pt->entry);
	if (new_font == NULL) 
	    new_font = pt1;
	else 
	    new_rear->next = pt1;
	new_rear = pt1;
    }

    font = new_font;
    rear = new_rear;
}
void Queue::operator=(const Queue &origin) {
    Node *new_font, *new_rear, *pt1, *origin_font = origin.font;

    new_font = new_rear = NULL;
    for (Node *pt = origin_font; pt != NULL; pt = pt->next) {
	pt1 = new Node(pt->entry);
	if (new_font == NULL) 
	    new_font = pt1;
	else 
	    new_rear->next = pt1;
	new_rear = pt1;
    }

    clear();

    font = new_font;
    rear = new_rear; 
}
