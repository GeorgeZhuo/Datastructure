// 2014.01.15

#include <iostream>
#include <queue>
#include <stdio.h>
#include <list>
#include <string.h>
using namespace std;

list<int> graph[100];
bool visited[100];

void bfs() {

    queue<int> hold;
    list<int> ::iterator it;
    memset(visited, false, sizeof(visited));
    
    hold.push(0);
    
    while (!hold.empty()) {
	
	int top = hold.front();
	if (!visited[top]) {
	    visited[top] = true;
	    cout << top << endl;

	    for (it = graph[top].begin(); it != graph[top].end(); it++)
		hold.push(*it);
	}

	hold.pop();
    }
}

int main () {
    
    int number;
    int temp;
    cin >> number;
    for (int i = 0; i < number; i++) {
	while(cin >> temp && temp != number)
	    graph[i].push_back(temp);
    }

    bfs();
    return 0;
}
