// 2013.10.08 

#include <iostream>
#include "Queue.h"

using namespace std;
int main () {
    Queue queue1;

    for (int i = 0; i < 10; i++) 
	queue1.append(i);

    for (int i = 0; i < 10; i++) {
	int item;
	queue1.retrieve(item);
	queue1.serve();
	cout << item << endl;
    }

    if (queue1.empty())
	cout << "Yes" << endl;
}
