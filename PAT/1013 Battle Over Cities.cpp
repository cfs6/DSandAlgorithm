//1013 Battle Over Cities

#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool connect[1024][1024];
bool visited[1024];
int n;

void dfs(int x, int q) {                       //dfs求连通分量     x:当前点 q:删除的点
	if (visited[x] == true)
		return;
	visited[x] = true;
	for (int i = 0; i < n; ++i) {
		if ((i != q) && connect[x][i]) {
			dfs(i, q);
		}
	}
}

int main() {
	int m, k;
	cin >> n >> m >> k;
	int x, y;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		--x;
		--y;
		connect[x][y] = connect[y][x] = true;
	}
	for (; k > 0;k--) {                             //q:删除的点
		int ans = 0, q;
		cin >> q;
		--q;
		memset(visited, 0, sizeof(visited));      
		for (int x = 0; x < n; ++x) {
			if ((x != q) && (!visited[x])) {
				dfs(x, q);
				ans++;
			}
		}
		--ans;
		cout << max(ans, 0) << endl;
	}

	system("pause");
}