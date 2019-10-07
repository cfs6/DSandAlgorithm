//BFS in matrix
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<sstream>

using namespace std;


vector<pair<int,int>> shortestpath(vector<vector<int>> matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	pair<int, int> start;
	pair<int, int> target;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] == 2)
				start = make_pair(i, j);
			if (matrix[i][j] == 3)
				target = make_pair(i, j);
		}
	}
	vector<pair<int, int>>path;
	vector<vector<bool>> visited(m, vector<bool>(n));
	queue<pair<int,int>> pathqueue;
//	vector<int> direction 
	pathqueue.push(start);
	while (!pathqueue.empty()) {
		pair<int, int> pcurrent = pathqueue.front();
		path.push_back(pcurrent);
		pair<int, int>pnext = getnext(matrix, pcurrent, visited);

	}

}

pair<int, int> getnext(vector<vector<int>> matrix, pair<int, int> current, vector<vector<bool>> visited) {
	int m = matrix.size();
	int n = matrix[0].size();
	int cf = current.first;
	int cs = current.second;
	pair<int, int>newpair = make_pair(-1, -1);
	if ((cs + 1 <= n - 1) && (visited[cf][cs + 1] == false)) {
		pair<int, int>newpair = make_pair(cf, cs + 1);
	}
	else if ((cf + 1 <= m - 1) && (*visited[cf + 1][cs] == false)) {
		pair<int, int>newpair = make_pair(cf, cs + 1);
	}
	else if ((cs - 1 >= 0) && (visited[cf][cs - 1] == false)) {
		pair<int, int>newpair = make_pair(cf - 1, cs);
	}
	else if ((cf - 1 >= 0) && (visited[cf - 1][cs] == false)) {
		pair<int, int>newpair = make_pair(cf - 1, cs);
	}
	return newpair;
}

vector<int> getvec(string str) {
	vector<int> res;
	stringstream ss;
	int r;
	while (ss >> r) {
		res.push_back(r);
	}
	return res;
}

int main() {
	vector<vector<int>> grid;
	string str;
	while (getline(cin, str)) {
		grid.push_back(getvec(str));
	}
	int m = grid.size();
	int n = grid[0].size();
	int start, target;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 2)
				start = i*n + j;
			if (grid[i][j] == 3)
				target = i*n + j;
		}
	}
	

}

