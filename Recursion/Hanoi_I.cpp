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
    
    cout << "Total step: " << endl;
    return 0;
}

void move(int count, int start, int finish, int temp) {
    
    int swap;
    while (count > 0) {
	move(count - 1, start, temp, finish);
	cout << "Move disk " << count <<  " from " << start 
	     << " to " << finish << endl;
	
	count--;
	swap = start;
	start = temp;
	temp = swap;
    }
}
