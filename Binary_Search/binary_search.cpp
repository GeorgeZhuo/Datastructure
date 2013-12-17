#ifndef BINARY_SEARCH_CPP
#define BINARY_SEARCH_CPP

bool recur_binary_1(int a[], int start, int end, int key) {

    if (start < end) {
	int mid = (start + end) / 2;
	if (a[mid] < key)
	    return recur_binary_1(a, mid + 1, end, key);
	else 
	    return recur_binary_1(a, start, mid, key);
    } else if (start > end)
	return false;
    else {
	if (a[start] == key)
	    return true;
	else
	    return false;
    }
}

bool loop_binary_1(int a[], int start, int end, int key) {

    while(start < end) {
	int mid = (start + end) / 2;
	if (a[mid] < key)
	    start = mid + 1;
	else
	    end = mid;
    }
    if (start > end)
	return false;
    else {
	if (a[start] == key)
	    return true;
	else
	    return false;
    }
}

bool recur_binary_2(int a[], int start, int end, int key) {
    
    if (start <= end) {
	int mid = (start + end) / 2;
	if (a[mid] == key)
	    return true;
	else if (a[mid] < key)
	    return recur_binary_2(a, mid + 1, end, key);
	else
	    return recur_binary_2(a, start, mid - 1, key);
    }
    else 
	return false;
}

bool loop_binary_2(int a[], int start, int end, int key) {
    while (start <= end) {
	int mid = (start + end) / 2;
	if (a[mid] == key)
	    return true;
	else if (a[mid] < key)
	    start = mid + 1;
	else 
	    end = mid - 1;
    }
    return false;
}

#endif
