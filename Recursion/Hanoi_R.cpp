// 2013.10.22 
#include <iostream>
#include <math.h>

using namespace std;

void move(int count, int start, int finish, int temp);

int main () {

    int count;
    cout << "Enter the number of the disks: ";
    cin >> count;
    
    move(count, 1, 2, 3);
    
    cout << "Total step: " << pow(2, count) - 1 << endl;
    return 0;
}

void move(int count, int start, int finish, int temp) {
    
    if (count == 1) return;
    else {
	move(count - 1, start, temp, finish);
	cout  << "Move disk " << count << " from " <<
	    start << " to "<< "finish"<<"." << endl;
	move(count - 1, temp, finish, start);
    }
}
