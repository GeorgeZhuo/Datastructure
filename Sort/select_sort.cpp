// 2014.01.15
// selection sort

/*  From divide the list into two part
 *  one is sorted and the other is unsorted
 *  usually regard the first one is sorted
 *  then from the second one to the length of 
 *  list, find the mini (or max) in the unsorted
 *  part, swap them.
*/

/*void swap(int *a, int *b) {
    
    int * temp;
    temp = a;
    a = b;
    b = temp;
    }*/

void select_sort(int a[], int N) {

    int lable;
    
    for (int i = 0; i < N; i++) {
	lable = i;
	
	for (int j = lable; j < N; j++) {
	    if (a[j] < a[lable])
		lable = j;
	}

	if (i != lable)
	    swap(a[i], a[lable]);
    }
}
