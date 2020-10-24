//1008 Elevator
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, s;
	vector<int> stair;
	stair.push_back(0);
	cin >> n;
	for (int k = 0; k < n; ++k) {
		cin >> s;
		stair.push_back(s);
	}
	int sum = 0;
	for (int i = 0; i < stair.size()-1; ++i) {
		if (stair[i + 1] > stair[i])
			sum += 6 * (stair[i + 1] - stair[i]);
		else
			sum += 4 * (stair[i] - stair[i + 1]);
	}
	sum += n * 5;
	cout << sum;
	system("pause");

}