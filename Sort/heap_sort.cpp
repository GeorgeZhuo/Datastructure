// This the heap sort including build a heap,
// insert a element.

#include <stdio.h>
#define MAX 100

int entry[MAX];
int count;

void insert_heap(int current, int low, int high) {

    int large; // the position of child of entry[low] with the larger key
    large = low * 2 + 1; // large now is the left child of low
    while (large <= high) {
	if (large < high && entry[large] < entry[large + 1])
	    large++;
	if (current >= entry[large])
	    break;
	else {
	    entry[low] = entry[large];
	    low = large;
	    large = low * 2 +1;
	}
    }
    entry[low] = current;
}

void build_heap() {

    int low;  // All entries beyond the position low form a heap
    // count / 2 - 1 is key of last parent node
    for (low = count / 2 - 1; low >= 0; low--) {
	int current = entry[low];
	insert_heap(current, 0, count - 1);
    }
}

void heap_sort() {
    int current;
    int last_unsorted;
    build_heap();
    for (last_unsorted = count - 1; last_unsorted > 0; last_unsorted--) {
	current = entry[last_unsorted];
	entry[last_unsorted] = entry[0];
	insert_heap(current, 0, count - 1);
    }
}

int main () {

    int i;
    printf("Nnter the number of list and the list\n");
    scanf("%d", &count);
    for (i = 0; i < count; i++)
	scanf("%d", &entry[i]);
    heap_sort();

    for (i = 0; i < count; i++)
	printf("%d ", entry[i]);
}
