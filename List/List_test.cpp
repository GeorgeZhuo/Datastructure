// 2013.11.12
// this the test for the List constructed by linked List

#include <iostream>
#include "List.h"
#include "Node.h"
#include "define.h"
#include "List.cpp"

using namespace std;

int main () {

    List<int> list1;

    for (int i = 0; i < 10; i++)
	list1.insert(i, i+1);

    if (list1.empty())
	cout << "It is a empty list" << endl;
    else 
	cout << "It is not empty" << endl;

    int a;
    list1.retrieve(3, a);
    cout << "This is the forth number in the list " << a << endl;

    int b;
    list1.replace(3, b);
    
    list1.remove(3, b);

    return 0;
}
