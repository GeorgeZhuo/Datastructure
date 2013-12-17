// 2013.10.22

#ifndef LIST_A
#define LIST_A

#include "define.h"

template <class List_entry>
class List_A{
public:
	List_A();
	int size() const;
	bool full() const;
	bool empty() const;
	void clear();
	void traverse(void(*visit)(List_entry &));
	Error_code retrieve(int position, List_entry &x) const;
	Error_code replace(int position, const List_entry &x);
	Error_code remove(int position, List_entry &x);
	Error_code insert(int position, const List_entry &x);

private:
	int count;
	List_entry entry[max_list];
};
#endif
