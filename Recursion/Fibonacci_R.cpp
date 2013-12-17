// 2013.10.22 

#include <iostream>
#include <time.h>

using namespace std;

int fibonacci(int n);

int main () {
    int number;
    
    clock_t TimeStart = clock();
    cout << "Enter the fibonacci number: ";
    cin >> number;

    cout << "The result: " << fibonacci(number) << endl;
    clock_t TimeEnd = clock();
    
    cout << "Time Used: " << (double)(TimeEnd - TimeStart)/CLOCKS_PER_SEC
	 << " second" << endl;
    return 0;
    
}

int fibonacci(int n) {

    if (n <= 0) 
	return 0;
    else if (n == 1)
	return 1;
    else
	return fibonacci(n - 1) + fibonacci(n - 2);
}
