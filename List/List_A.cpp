// 2013.10.30

#include "define.h"
#include "List_A.h"

template <class List_entry>
List_A<List_entry>::List_A() {
    count = 0;
}

template <class List_entry>
int List_A<List_entry>::size() const {

    return count;
}

template <class List_entry>
bool List_A<List_entry>::full() const {

    return (count == max_list);
}

template <class List_entry>
bool List_A<List_entry>::empty() const {

    return (count == 0);
}

template <class List_entry>
void List_A<List_entry>::clear() {

    count = 0;
}

template <class List_entry>
void List_A<List_entry>::traverse(void(*visit)(List_entry &)) {

    for (int i = 0; i < count; i++)
	(*visit)(entry[i]);
}

template <class List_entry>
Error_code List_A<List_entry>::retrieve(int position, List_entry &x) const {

    if (position < 0 || position > count)
	return range_error;
    if (count == 0) 
	return underflow;

    x = entry[position];

    return success;
}

template <class List_entry>
Error_code List_A<List_entry>::replace(int position, const List_entry &x) {

    if (position < 0 || position > count)
	return range_error;

    entry[position] = x;

    return success;
}

template <class List_entry>
Error_code List_A<List_entry>::remove(int position, List_entry &x) {

    if (position < 0 || position > count) 
	return range_error;
    if (count == 0)
	return underflow;

    x = entry[position];
    for (int i = position; i < count - 1; i++)
	entry[i] = entry[i + 1];

    count--;
    return success;
}

template <class List_entry>
Error_code List_A<List_entry>::insert(int position, const List_entry &x) {

    if (count == max_list) 
	return overflow;
    if (position < 0 || position > count)
	return range_error;

    for (int i = count -1; i >= position; i--)
	entry[i + 1] = entry[i];

    entry[position] = x;
    count++;

    return success;
}
