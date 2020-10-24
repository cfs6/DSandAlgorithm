//Dijstra
#include<iostream>
#include<vector>
#include<limits>
using namespace std;
const int inf = numeric_limits<int>::max();

void ShortestPath(vector<vector<int>> array, int src) {
	int n = array[0].size();
	vector<int> path(n);
	vector<int> dist(n);
	vector<bool> mark(n);
	for (int i = 0; i < n; ++i) {
		if (array[src][i] != inf)
			dist[i] = array[src][i];
		else
			dist[i] = inf;
		mark[i] = false;
		if ((src != i) && dist[i] != inf)
			path[i] = src;
		else
			path[i] = -1;
	}


	dist[src] = 0;
	path[src] = src;
	mark[src] = true;


	for (int i = 0; i < n; ++i) {
		int k = 0;
		for (int j = 0; j < n; ++j) {
			if ((!mark[j]) && (dist[j] < dist[k]))
				k = j;
		}
		mark[k] = true;

		for (int j = 0; j < n; ++j) {
			if (dist[k] < inf) {
				int temp = array[k][j] + dist[k];
				if ((!mark[j]) && (temp < dist[j])) {
					dist[j] = temp;
					path[j] = k;
				}
			}
		}
	}
} 
