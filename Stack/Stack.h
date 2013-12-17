// 2013.10.08

#ifndef STACK_H
#define STACK_H

#include "Define.h"

class Stack {
public:
	Stack();
	~Stack();
	Error_code push(const Stack_entry&);
	Error_code pop();
	Error_code top(Stack_entry&) const;
	Error_code clear();
	bool empty() const;

	void operator =(const Stack &origin);
	Stack(const Stack &origin);
private:
	Node *top_;
};

#endif  
