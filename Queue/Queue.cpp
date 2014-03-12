// 2013.10.15

#include "Queue.h"
#include "Define.h"

// create a queue and let it empty
Queue::Queue() {
    font = rear = NULL;
}
// clear the queue, when the deconstructor was called
Queue::~Queue() {
    clear();
}

/* append a new at the end of the queue
 * if the queue is empty, let front and rear both points to the add_one
 * else do nothing to front, just let the rear_node points to the add_one
 * and rear also.
*/
Error_code Queue::append(const Queue_entry &item) {
    Node *new_node = new Node(item);

    if (new_node == NULL) return overflow;
    
    // if the queue is empty
    if (font == NULL) 
	font = new_node;
    else
	rear->next = new_node;
	
    rear = new_node;
    return success;
}

/* dequeue the front node of the queue, shift the front to the
 * next node, if queue becomes empty after dequeued, we should
 * let rear and front both points to the ground. then delete 
 * delete the node
*/
Error_code Queue::serve() {
    Node *old_node = font;

    if (font == NULL) return underflow;
    
    font = font->next;
    // if the queue is empty after serving, we must
    // set rear to NULL
    if ( font == NULL) rear = NULL;
    delete old_node;

    return success;
}

// get the front record of queue
Error_code Queue::retrieve(Queue_entry &item) const {
    if (font == NULL) return underflow;

    item = font->entry;
    return success;
}

// check wheter the queue is empty or not
bool Queue::empty() const {
    return (font == NULL);
}

// delete all the node in the queue
// after clear all the node, we should let front and
// rear both points the ground
Error_code Queue::clear() {
    Node *old_node;
    for (Node *pt = font; pt != NULL; pt = pt->next) {
	old_node = font;
	font = font->next;

	if (font == NULL) rear = NULL;
	delete old_node;
	
    }
}
// creat a new queue from the other, and let
// the front points copy_front and rear points
// to the copy_rear
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

// create a new queue from the other, and clear the old
// queue, let front points the copy_front and rear points
// copy_rear
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
