#include <iostream>
#include "define.h"
#include "List_A.h"
#include "List_A.cpp"

using namespace std;

int main () {

    List_A<int> list1;
    int one;

    for (int i = 0; i < 10; i++)
	list1.insert(i, i + 1);

    for (int i = 0; i < 10; i++){
	int temp;
	list1.retrieve(i, temp);
	cout << temp << endl;
    }

    list1.replace(2, 100);
    list1.remove(5, one);
    list1.insert(4, 14);

    for (int i = 0; i < 10; i++){
	int temp;
	list1.retrieve(i, temp);
	cout << temp << endl;
    }
    return 0;
}
