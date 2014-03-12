// 2013.11.23
// emage sort implement in array

#include <iostream>
#include <algorithm>

// merge the two sublist
void merge(int a[], int first_low,
	   int second_low, int second_high) {

    int low1 = first_low;
    int low2 = second_low;
    int first_high = second_low - 1;
    int low = first_low;
    int temp[second_high + 1];

    while (low <= second_high) {
	
	// if the entry in the first array is smaller than
	// the entry in the second array, then it will tempe
	// copied to array temp or if the second array is exhualsted
	// copy all the entries in the first array to temp
	if ((low2 > second_high || a[low1] <= a[low2]) &&
	    low1 <= first_high) {
	    temp[low++] = a[low1++];
	} else if ((low1 > first_high ||a[low1] > a[low2]) &&
		   low2 <= second_high) {
	    temp[low++] = a[low2++];
	}
    }
    // copy the data in the temp to array
    for (int i = first_low; i <= second_high; i++)
	a[i] = temp[i];

}

void merge1(int a[], int fLow, int sLow, int sHight ) {

    int LHight = sLow - 1;
    int temp[sHight + 1];
    int position = fLow;
    int low = fLow;

    // choose the smaller in the left or in the right
    // copy it to the temp
    while (fLow <= LHight && sLow <= sHight) {
	if (a[fLow] <= a[sLow])
	    temp[position++] = a[fLow++];
	else
	    temp[position++] = a[sLow++];
    }

    // if the first half is not empty, copy the 
    // rest of fist half
    while (fLow <= LHight)
	temp[position++] = a[fLow++];
    // if the second half is not empty, copy 
    // the rest of the second half
    while (sLow <= sHight)
	temp[position++] = a[sLow++];

    for (int i = low; i <= sHight; i++) {
	a[i] = temp[i];
    }

}
// divide the list into two smaller sublist
// merge sort the sublist, then merge the sublist
// using recursion
void merge_sort(int a[], int low, int high) {

    if (low < high) {
	int mid = (low + high) / 2;

	merge_sort(a, low, mid);
	merge_sort(a, mid + 1, high);

	merge1(a, low, mid + 1, high);
    }
}
