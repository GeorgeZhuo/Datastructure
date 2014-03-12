// 2013.11.23
// quick sort function definition

#include <iostream>

using namespace std;

void qsort(int a[],int low, int high) {

    int last_low = low;
    int last_high = high;
    int pivot = a[(last_low + last_high) / 2];

    do {
	while (pivot > a[last_low])
	    last_low++;
	while (pivot < a[last_high])
	    last_high--;
	
	if (last_low <= last_high) {
	    int temp = a[last_low];
	    a[last_low] = a[last_high];
	    a[last_high] = temp;
	    last_low++;
	    last_high--;
	}
    } while (last_low <= last_high);

    if (last_low < high)
	qsort(a, last_low, high);
    if (low < last_high)
	qsort(a, low, last_high);
}

void qsort1(int a[], int low, int high) {
    if (low < high) {

    	int pivot = (low + high) / 2;

	swap(a[pivot], a[low]);
	int last_small = low;

	for (int i = low + 1; i <= high; i++) {
	    if (a[i] < a[low])
		swap(a[i], a[++last_small]);
	}
	swap(a[last_small], a[low]);
    
	qsort1(a, last_small + 1, high);
	qsort1(a, low, last_small - 1);
    }
}

void swap(int *a, int *b) {
    int *temp;
    temp = a;
    a = b;
    b = temp;
   
}
