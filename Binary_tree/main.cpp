#include <iostream>
#include "Binary_tree.cpp"

using namespace std;

void visit(int &x) {
    cout << x << endl;
}
int main () {
    Binary_tree<int> a;

    for (int i = 0; i < 10; i++) 
	a.insert(i);

    a.preorder(visit);
    a.inorder(visit);
    a.posorder(visit);
}
