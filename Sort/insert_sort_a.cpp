// 2013.11.19
// this is the definition of a insert sort

template <class Entry>
void insert_sort_a(Entry a[], int N) {

    int position;
    Entry current;
    for (int i = 1; i < N; i++) {
	current = a[i];
	position = i;
	if (a[i] < a[i - 1]) {
	    do {
		a[position] = a[position - 1];
		position--;
	    } while (position > 0 && a[position - 1] > current);
	    a[position] = current;
	}
    }
}
