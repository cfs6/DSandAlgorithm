#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int main() {
	int m, n;
	cin >> n >> m;
	string str;
	vector<int> nonLeafNode(n);
	vector<vector<int>> tree(n, vector<int>(n));

	int node, childnode, childnum;
	vector<vector<int>> nodeRelation;
	for (int i = 0; i < m; ++i) {
		vector<int> temp;
		cin >> node;
		nonLeafNode[i] = node;
		temp.push_back(node);
		cin >> childnum;
		vector<int> levelNode;
		for (int j = 0; j < childnum; ++j) {
			int child;
			cin >> child;
			temp.push_back(child);
		}
		nodeRelation.push_back(temp);
	}
	for (int i = 0; i < tree.size(); ++i) {
		for (int j = 0; j < tree[i].size(); ++j) {
			tree[i][j] = 0;
		}
	}
	if (n != 0) {
		tree[0][0] = 1;
	}
	else {
		cout << "0";
		return 0;
	}

	for (int i = 0; i < nodeRelation.size(); ++i) {
		int node = nodeRelation[i][0];

		for (int k = 0; k < tree.size(); ++k) {
			for (int l = 0; l < tree[k].size(); ++l) {
				if (node == tree[k][l]) {
					int index = k + 1;

					for (int j = 1; j < nodeRelation[i].size(); ++j) {

						for (int a = 0; a < tree[index].size(); ++a) {
							if (tree[index][a] == 0) {
								tree[index][a] = nodeRelation[i][j];
								break;
							}
							
						}
					}
				}
			}
		}
	}
	/*
	for (int i = 0; i < tree.size(); ++i) {
		for (int j = 0; j < tree[i].size(); ++j) {
			cout << tree[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	vector<int> count;
	for (int i = 0; i < tree.size(); ++i) {
		int c = 0;
		for (int j = 0; j < tree[i].size(); ++j) {
			if (tree[i][j] != 0)
				c++;
		}
		for (int j = 0; j < tree[i].size(); ++j) {
			if (tree[i][j] != 0) {
				int node = tree[i][j];
				
				for (int k = 0; k < nodeRelation.size(); ++k) {
					if (node == nodeRelation[k][0]) {
						c--;
					}
				}
			}
		}
		count.push_back(c);
	}
	int outp = 0;
	for (int i = 0; i < tree.size(); ++i) {
		if (tree[i][0] != 0)
			outp++;
	}
	
	for (int i = 0; i < outp-1; ++i) {
		cout << count[i] << " ";
	}
	cout << count[outp-1];

	
	system("pause");
}