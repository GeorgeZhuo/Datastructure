// 2013.11.23
// emage sort implement in array

#include <algorithm>

void merge(int a[], int first_low, int first_high, int second_low, int second_high) {

    int low1 = first_low;
    int low2 = second_low;
    int low = first_low;
    int b[second_high + 1];

    while (low <= second_high) {

	if ((low2 > second_high || a[low1] <= a[low2]) && low1 <= first_high) {
	    b[low] = a[low1];
	    low++;
	    low1++;
	}
	else if ((low1 > first_high ||a[low1] > a[low2])&& low2 <= second_high) {
	    b[low] = a[low2];
	    low++;
	    low2++;
	}
    }
    for (int i = first_low; i <= second_high; i++)
	a[i] = b[i];

}

void merge_sort(int a[], int low, int high) {

    if (high - low <= 1) {
	if (a[low] > a[high])
	    std::swap(a[low], a[high]);
	return;
    }
    int mid = (low + high) / 2;

    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);

    merge(a, low, mid, mid + 1, high);
} 
/*
  void merge(int a[], int s1, int e1, int s2, int e2) {
  int i = s1, j = s2;
  int b[e2 + 1];
  int cnt = s1;

  while (cnt <= e2) {
  if ((j > e2 || a[i] <= a[j]) && i <= e1) {
  b[cnt] = a[i];
  cnt++;
  i++;
  }
  else if ((i > e1 || a[i] > a[j]) && j <= e2){
  b[cnt] = a[j];
  cnt++;
  j++;
  }
  }

  for (int i = s1; i <= e2; i++)
  a[i] = b[i];
  }

  void merge_sort(int a[],int l, int h) {
  if (h - l <= 1) {
  if (a[l] > a[h])
  swap(a[l], a[h]);
  return;
  }

  int mid = (h + l) / 2;
  merge_sort(a, l, mid);
  merge_sort(a, mid + 1, h);

  merge(a, l, mid, mid + 1, h);
  } 

*/
