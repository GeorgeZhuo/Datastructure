// 2013.11.19
// this the code for test the sort method

#include <stdio.h>
#include "insert_sort_a.cpp"
#include "qsort.cpp"
#include "merge_sort.cpp"
#include "shellsort.cpp"
#include "select_sort.cpp"

int main () {
    
    int a[10] = {7, 2, 5, 1, 0, 9, 8, 3, 6, 4};
    int b[10] =  {7, 2, 5, 1, 0, 9, 8, 3, 6, 4};
    
    merge_sort(a, 0, 9);
    select_sort(b, 10);
    for (int i = 0; i < 10; i++) {
	printf("%d\n", a[i]);
    }
   /* for (int i = 0; i < 10; i++) {
	printf("%d\n", b[i]);
	}*/

    return 0;
}
