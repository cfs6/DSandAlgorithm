//二人博弈。用dfs遍历了两次，找到两人能访问的中间结点，和各自一边的节点。
//中间结点数为偶数，两人平分；为奇数，牛牛多取一个。牛牛先手，胜利条件是牛牛能取的点要比牛妹多
#include<vector>
#include<iostream>
#include<string>
using namespace std;

vector<vector<int>> piece(100005,vector<int>(100005));
bool visit1[100005], visit2[100005];
int n, m, a, b, t;

void dfs1(int index) {
	if (index == n)
		return;
	visit1[index] = true;
	for (int i = 0; i < piece[index].size(); ++i) {
		if (visit1[piece[index][i]] == false)
			dfs1(piece[index][i]);
	}
}

void dfs2(int index) {
	if (index == 1)
		return;
	visit2[index] = true;
	for (int i = 0; i < piece[index].size(); ++i) {
		if (visit2[piece[index][i]] == false)
			dfs2(piece[index][i]);
	}
}


int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 100005; ++i) {
			visit1[i] = 0;
			visit2[i] = 0;
			piece[i].clear();
		}
		for (int i = 0; i < n - 1; ++i) {
			cin >> a >> b;
			piece[a].push_back(b);          //连接关系用二维数组表示
			piece[b].push_back(a);
		}
		dfs1(1);
		dfs2(n);
		int res1 = 0, res2 = 0;
		for (int i = 2; i < n; ++i) {
			if (visit1[i]) {
				if (visit2[i]) {
					res1++;
					res2++;
				}
				else {
					res1 += 2;
				}
			}
			else
				res2 += 2;
		}
		res1 = res1 / 2 + res1 % 2;
		res2 = res2 / 2;
		if (res1 > res2)
			cout << "NIUNIU";
		else
			cout << "NIUMEI";
		cout << endl;
	}
	
	system("pause");
}

