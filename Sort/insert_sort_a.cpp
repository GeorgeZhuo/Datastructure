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

template <class Entry>
void insert_sort_a1(Entry a[], int N) {
    
    int position;
    Entry current;

    for (int i = 1; i < N; i++) {
	
	position = i;
	current = a[i];
	
	if (a[i] < a[i -1]) {
	    for (; position > 0 && a[position - 1] > current; position--)
		a[position]= a[position - 1];

	    a[position] = current;
	}
    }
}

template <class Entry> 
void insert_sort_a2(Entry a[], int N) {

    int position;
    int current;

    for (int i = 0; i < N; i++) {
	current = a[i];
	position = i - 1;
	
	while (position > 0 && a[position] > current) {
	    a[position + 1] = a[position];
	    position--;
	}
	a[position + 1] = current;
	
    }
}
