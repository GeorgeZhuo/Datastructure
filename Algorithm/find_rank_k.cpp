// 2014.02.04

/*
 * find the element of rank k
 * in linear time by using the quicksort
 * idea partitioning the list into two sublist
*/

#include <iostream>

using namespace std;

int find_rank(int low, int high, int k);
int swap(int *a, int *b);
int partition(int low, int high);
int A[100];
int size;

int main () {
    
    int rank;

    cout << "input the array size" << endl;
    cin >> size;
    for (int i = 0; i < size; ++i) {
	cin >> A[i];
    }
    
    cout << "input the rank k to find" << endl;
    cin >> rank;
    rank = find_rank(0, size - 1, rank - 1);

    cout << "the k element in array is: " << A[rank] << endl;
    return 0;
}

int find_rank(int low, int high, int k) {
    
    if (low < high) {
	
	int pivot = partition(low, high);
	
	if (pivot == k)
	    return pivot;
	else if (pivot < k)
	    find_rank(pivot, high, k);
	else
	    find_rank(low, pivot, k);
    }
    
}

int swap(int *a, int *b) {
    int *temp;
    temp = a;
    a = b;
    b = temp;
}

int partition(int low, int high) {

    int pivot = (low + high) / 2;

    int last_small = low;

    swap(A[low], A[pivot]);
    
    for (int i = low + 1; i <= high; i++) {
	
	if (A[i] <= A[low]) {
	    swap(A[i], A[++last_small]);
	}
    }

    swap(A[low], A[last_small]);

    return last_small;

}
