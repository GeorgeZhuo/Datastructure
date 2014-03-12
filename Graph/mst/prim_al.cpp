// 2013.12.31
// prim's algorithm to get a minimum spanning tree

/* 
   step 0: choose any elememt r in V, set S = {r}
   and A = empty.
   step 1: find a lightest edge such that one endpoit is in S
   and the other is in V / S. Add this edge to A and it's
   other endpoint to S.
   step 2: if V/S is empty, then stop, otherwise go step 1.
*/

#include <iostream>
#include <string.h>
#define MAX 100
#define INF 1000000000

using namespace std;

int graph[MAX][MAX];
int lowcost[MAX];
bool visited[MAX];
int source;
int nodenum;
int sum;

void prim() {

    int lable;
    int mini;
    source = 0;
    memset(visited, false, sizeof(visited));
  
    // init the adjacency edge and S
    visited[source] = true;
    for (int i = 0; i < nodenum; i++)
	lowcost[i] = graph[source][i];

    for (int i = 1; i < nodenum; i++) {
	mini = INF;
	// find the lightest adjacency edge
	for (int j = 0; j < nodenum; j++) 
	    if (!visited[j] && lowcost[j] < mini) {
		lable = j;
		mini = lowcost[lable];
	    }

	if (mini < INF) {
	    // add the new edge
	    visited[lable] = true;
	    sum += mini;
	    
	    // update the adjacency edge
	    for (int k = 0; k < nodenum; k++)
		if (!visited[k] && graph[lable][k] < lowcost[k])
		    lowcost[k] = graph[lable][k];	
	} else break;
    }
}

int main () {

    while (cin >> nodenum) {
	memset(graph, INF, sizeof(graph));
	sum = 0;
	for (int i = 0; i < nodenum; i++)
	    for (int j = 0; j < nodenum; j++)
		cin >> graph[i][j];

	prim();
	cout << sum << endl;
    }
}


