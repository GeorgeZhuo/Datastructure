/* 
 * this the code of Factorial by using iteration
 * n! = n * (n -1)*....* 2 * 1
 */

#include <iostream> 

using namespace std;

int factorial(int n) {

    int result = 1;
    for (int i = 1; i <= n; i++) {
	result *= i;
    }

    return result;
}

int main () {
    int number;
    
    cout << "Enter the number of factorial: ";
    cin >> number;

    cout << factorial(number) << endl;
    
    return 0; 
}
