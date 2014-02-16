// 2014.01.01

/*
 *  Kruskal algorithm to span a mininum tree
 *  step 1: choose a lightest weight in E and let A empty
 *  step 2: Find a lightest weight in E that will not make
 *          cycle with E, then E <- E - e, A = A + e
 *  step 3: repeat step 2 until the number of E is equal to n - 1
 */

typedef struct Kruskal {
    int parent;
    int son;
    int weight;
};

int find(int x) {
    return x == father[x] ? x : find(father[x]);
}

void unionset(int x, int y) {
  
    int root1, root2;
    root1 = find(x);
    root2 = find(y);
  
    if (root1 != root2) {
	if (son[root1] >= son[root2]) {
	    father[root2] = root1;
	    son[root1] += son[root2];
	} else {
	    father[root1] = root2;
	    son[root2] += son[root1];
	}
    }
}

int main () {

    while (cin >> nodenum) {
	for (int i = 0; i < nodenum; i++)
	    for (int j = 0; j < nodenum; j++)
		cin >> 
		    }
}

