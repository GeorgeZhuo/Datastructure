// 2013.10.08

#include "Stack.h"
#include "Define.h"

Stack::Stack() {
    top_ = NULL;
}
Stack::~Stack() {
    clear();
}
Error_code Stack::push(const Stack_entry &item) {

    Node *temp = new Node(item);
    if (temp == NULL) 
	return overflow;
    else 
	temp->next= top_;
    top_ = temp;

    return success;
}
Error_code Stack::pop() {
    if (top_ == NULL) return underflow;
    
    Node *temp = top_;
    top_ = top_->next;

    delete temp;

    return success;
}
Error_code Stack::top(Stack_entry &item) const {
    if (top_ == NULL) 
	return underflow;
    item = top_->entry;

    return success;
}
bool Stack::empty() const {
    return (top_ == NULL);
}
void Stack::operator=(const Stack &origin) {
    Node *new_top, *tail, *pt1, *origin_node = origin.top_;
    new_top = NULL;
    for (Node *pt = origin_node; pt != NULL; pt = pt->next) {
	pt1 = new Node(pt->entry);	
	if (new_top == NULL) 
	    new_top = pt1;
	else
	    tail->next = pt1;
	tail = pt1;
    }
    
    Node *old_node;
    for (Node *pt = top_; pt != NULL; pt = pt->next) {
	old_node = top_;
	top_ = top_->next;
	
	delete old_node;
    }
    
    top_ = new_top;
}
Stack::Stack(const Stack &origin) {
    Node *new_top, *tail, *pt1, *origin_node = origin.top_;
    new_top = NULL;
    for (Node *pt = origin_node; pt != NULL; pt = pt->next) {
	pt1 = new Node(pt->entry);	
	if (new_top == NULL) 
	    new_top = pt1;
	else
	    tail->next = pt1;
	tail = pt1;
    }
    
    top_ = new_top;
}

Error_code Stack::clear() {
    Node *old_node;
    for (Node *pt = top_; pt != NULL; pt = pt->next) {
	old_node = top_;
	top_ = top_->next;
	
	delete old_node;
    }

    return success;   
}
