// 2013.10.22

#include <iostream>
#include <time.h>

using namespace std;

int fibonacci(int n);

int main () {

    clock_t TimeStart = clock();
    int number;
    
    cout << "Enter the fibonacci number: ";
    cin >> number;

    cout << "The result: " << fibonacci(number) << endl;
    
    clock_t TimeEnd =  clock();

    cout << "Time Used:" << TimeEnd - TimeStart << endl;
    return 0;
    
}

int fibonacci(int n) {

    int f1, f2, current;

    if (n <= 0) return 0;
    else if (n == 1) return 1;
    else {
	f1 = 0;
	f2 = 1;
	for (int i = 2; i <= n; i++) {
	    current = f1 + f2;
	    f1 = f2;
	    f2 = current;
	}

	return current;
    }
}
