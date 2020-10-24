//1011 World Cup Betting
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

int main() {
	string str;
	vector<vector<float>> score(3);
	float s;
	for (int i = 0; i < 3; ++i) {
		getline(cin, str);
		stringstream ss;
		ss << str;
		while(ss >> s)
			score[i].push_back(s);

	}

	vector<float> res;
	vector<int> resindex;
	float max;
	int index;
	for (int i = 0; i < score.size(); ++i) {
		max = 0.0;
		index = 0;
		for (int j = 0; j < score[i].size(); ++j) {
			if (max < score[i][j]) {
				max = score[i][j];
				index = j;
			}
		}
		res.push_back(max);
		resindex.push_back(index);
	}
	for (auto rindex : resindex) {
		switch (rindex) {
		case 0:
			cout << "W" << " ";
			break;
		case 1:
			cout << "T" << " ";
			break;
		case 2:
			cout << "L" << " ";
			break;
		default:
			break;
		}
	}
	float resprofit = 1.0;
	for (int i = 0; i < res.size(); ++i) {
		resprofit *= res[i];
	}
	resprofit = (resprofit*0.65 - 1.0) * 2.0;
	cout.flags(ios::fixed);
	cout.precision(2);
	cout << resprofit;

	system("pause");
}