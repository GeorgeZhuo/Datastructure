// 2013.10.08 

#include <iostream>
#include "Stack.h"

using namespace std;
int main () {
    Stack stack1;

    for (int i = 0; i < 10; i++) 
	stack1.push(i);

    for (int i = 0; i < 10; i++) {
	int item;
	stack1.top(item);
	stack1.pop();
	cout << item << endl;
    }

    if (stack1.empty())
	cout << "Yes" << endl;
}
