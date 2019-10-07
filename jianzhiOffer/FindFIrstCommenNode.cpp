#include<iostream>
#include<vector>
using namespace std;

vector<int> splitnum(int num) {
	vector<vector<int>> r;
	vector<int> digit;

	int count = 0;
	int n = num;
	while (n != 0) {
		n /= 10;
		count++;
	}
	for (int i = count; i>0; --i) {
		int d = num / (pow(10, i - 1));
		if (d / 10 == 0) {
			digit.push_back(d);
		}
		else {
			d = d % 10;
			digit.push_back(d);
		}
	}
	return digit;
}

vector<vector<int>> CombineNum(vector<int> num) {
	int numsize = num.size();
	vector<vector<int>> res;
	vector<int> r;
	bool isvisit;
	for (int i = 0; i < numsize - 1; ++i) {
		int d = num[i] * 10 + num[i + 1];
		r.clear();
		if (d<26) {
			for (int j = 0; j < numsize - 1; ++j) {
				if (j == i) {
					r.push_back(d);
					j++;
				}
				else {
					r.push_back(num[j]);
				}
			}
		}
		res.push_back(r);
	}
	return res;
}

int main() {
	vector<int> res = splitnum(12345);
	vector<vector<int>> nres=CombineNum(res);

	for (auto  nr : nres) {
		for (int i = 0; i < nr.size(); ++i) {
			cout << nr[i] << " ";
			cout << endl;
		}
	}

	system("pause");
}
