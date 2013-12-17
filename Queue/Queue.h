// 2013.10.15 

#ifndef QUEUE_H
#define QUEUE_H

#include "Define.h"

class Queue {
public:
	Queue();
	~Queue();
	Queue(const Queue &origin);
	void operator=(const Queue &origin);

	Error_code append(const Queue_entry &);
	Error_code serve();
	Error_code retrieve(Queue_entry &item) const;
	bool empty() const;
	Error_code clear();
private:
	Node *font, *rear;

};
#endif
