//1009 Product of Polynomials
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n1, n2;
	vector<pair<int, double>> num1, num2;
	int exp;
	double coe;
	cin >> n1;
	for (int i = 0; i < n1; ++i) {
		cin >> exp;
		cin >> coe;
		pair<int, double> p1= make_pair(exp, coe);
		num1.push_back(p1);
	}
	cin >> n2;
	for (int i = 0; i < n2; ++i) {
		cin >> exp;
		cin >> coe;
		pair<int, double> p2 = make_pair(exp, coe);
		num2.push_back(p2);
	}

	vector<pair<int, double>> res, resnum;
	for (int i = 0; i < num1.size(); ++i) {
		for (int j = 0; j < num2.size(); ++j) {
			int resexp = num1[i].first + num2[j].first;
			double rescoe = num1[i].second*num2[j].second;
			pair<int, double> respair = make_pair(resexp, rescoe);
			res.push_back(respair);

		}
	}
	for (int i = 2000; i >= 0;--i) {
		double sumcoe = 0.00;
		for (int j = 0; j < res.size(); ++j) {
			if (res[j].first == i) {
				sumcoe += res[j].second;
			}
		}
		if (sumcoe != 0) {
			pair<int, double> rs = make_pair(i, sumcoe);
			resnum.push_back(rs);
		}	
	}
	if (resnum.size() == 0) {
		cout << "1" << " " << "0" << " " << "0";
		return 0;
	}
	cout.flags(ios::fixed);
	cout.precision(1);
	cout << resnum.size() << " ";
	for (int k = 0; k < resnum.size()-1; ++k) {
		cout << resnum[k].first << " " << resnum[k].second << " ";
	}
	cout << resnum[resnum.size() - 1].first << " " << resnum[resnum.size() - 1].second;
	system("pause");
}
