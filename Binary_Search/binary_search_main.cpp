// 2013.11.12
// this the test for binary search

#include <iostream>
#include "binary_search.cpp"
#define N 20

using namespace std;

int main () {

    int a[N];
    
    for (int i = 0; i < N; i++)
	a[i] = i + 2;

    if (recur_binary_1(a, 0, N - 1, 30))
	cout << "Found" << endl;
    else
	cout << "Not found" << endl;

    if (loop_binary_1(a, 0, N - 1, 12))
	cout << "Found" << endl;
    else
	cout << "Not found" << endl; 

    if (recur_binary_2(a, 0, N - 1, 12))
	cout << "Found" << endl;
    else
	cout << "Not found" << endl;

    if (loop_binary_2(a, 0, N - 1, 12))
	cout << "Found" << endl;
    else
	cout << "Not found" << endl;

    return 0;
}
