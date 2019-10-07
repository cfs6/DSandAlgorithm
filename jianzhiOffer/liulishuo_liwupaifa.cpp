#include<iostream>
#include<vector>
#include<algorithm>
//#include<utility>
using namespace std;
bool compare_(pair<int,int> a, pair<int,int> b) {
	return a.second > b.second;
}

int main() {
	int n, a, b,x, y;
	cin >> n >> a >> b;
	vector<int> pa;
	vector<int> pb;
	vector<pair<int, int>> ppair;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		pa.push_back(x);
		pb.push_back(y);
		ppair.push_back(make_pair(i, x>y?(x-y):(y-x)));
	}
	sort(ppair.begin(), ppair.end(), compare_);
	int counta = 0, countb = 0, cost = 0;
	for (int i = 0; i < n; ++i) {
		if (counta < a && countb < b) {
			if (pa[ppair[i].first] > pb[ppair[i].first]) {
				cost += pb[ppair[i].first];
				counta++;
			}
			else {
				cost += pa[ppair[i].first];
				countb++;
			}
		}
		else if(counta==a&&countb<b){
			cost += pb[ppair[i].first];
			countb++;
		}
		else if (counta < a&&countb == b) {
			cost += pa[ppair[i].first];
			counta++;
		}
	}
	cout << cost;
	return 0;
}