#include <iostream>
#define MAX 100

using namespace std;

int find_maxsub();
int find_maxsub_r(int low, int high);
int find_cross_maxsub(int low, int high);

int A[MAX];
int size;

int main () {

    int sum;
   
    cout << "input the size of the array" << endl;
    cin >> size;

    for (int i = 0; i < size; i++) 
	cin >> A[i];
    sum = find_maxsub();

    for (int i = 0; i < size; ++i) {
	cout << A[i] << endl;
    }
    cout << sum << endl;
    sum = find_maxsub_r(0, size - 1);
    cout << sum << endl;

    return 0;
}

int find_maxsub() {
    int temp;
    int sum = 0;

    for (int i = 0; i < size; ++i) {
	temp = 0;
	for (int j = i; j < size; j++) {
	    temp += A[j];
	    if (temp > sum) {
		sum = temp;
	    }
	}
    }

    return sum;
}

int find_cross_maxsub(int low, int high) {
    
    int mid = (low + high) / 2;
    int left_sum = -100000;
    int sum = 0;

    for (int i = mid; i >= 0; i--) {
	sum = sum + A[i];
	if (sum > left_sum)
	    left_sum = sum;
    }
    
    int right_sum = -10000;
    sum = 0;

    for (int i = mid + 1; i <= high; ++i) {
	sum += A[i];
	if (sum > right_sum)
	    right_sum = sum;
    }

    return (right_sum + left_sum);
}
int find_maxsub_r(int low, int high) {

    if (low == high)
	return A[low];
    else {
	int mid = (low + high) / 2;
	int left_sum = find_maxsub_r(low, mid);
	int right_sum = find_maxsub_r(mid + 1, high);
	int cross_sum = find_cross_maxsub(low, high);

	if (left_sum >= right_sum && left_sum >= cross_sum)
	    return left_sum;
	else if (right_sum >= left_sum && right_sum >= cross_sum)
	    return right_sum;
	else
	    return cross_sum;
    }
}
