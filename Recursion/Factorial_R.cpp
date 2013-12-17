// 2013.10.22

#include <iostream>
#include <math.h>

using namespace std;

int factorial(int n) {

    if (n == 0 || n == 1) 
	return 1;
    else 
	return n * factorial(n - 1);
}

int main () {
    int number;
    
    cout << "Enter the number of factorial: ";
    cin >> number;

    cout << factorial(number) << endl;
    
    return 0; 
}
