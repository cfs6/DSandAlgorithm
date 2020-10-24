//1002 A+B for Polynomials
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

int main() {
	string a, b;
	float fa, fb;
	int n1, n2;
	vector<float> poly1;
	vector<float> poly2;
	getline(cin, a);
	getline(cin, b);
	stringstream sa(a);
	sa >> n1;
	while (sa >> fa) {
		poly1.push_back(fa);
	}
	stringstream sb(b);
	sb >> n2;
	while (sb >> fb) {
		poly2.push_back(fb);
	}
	int maxp = (poly1[0] > poly2[0]) ? poly1[0] : poly2[0];
	vector<float> res(maxp + 1);

	vector<float>::iterator it1, it2;
	for (it1 = poly1.begin(); it1 != poly1.end(); ++it1) {
		int i = *it1;
		++it1;
		res[i] = *it1;                                         
	}
	for (it2 = poly2.begin(); it2 != poly2.end(); ++it2) {
		int j = *it2;
		++it2;
		res[j] += *it2;
	}

	int count = res.size();
	if (count == 1) {
		if (res[0] == 0) {
			cout.flags(ios::fixed);
			cout.precision(1);
			cout << "1" << " " << "0" << " " << "0";
		}
		else {
			cout << count << "0" << res[0];
		}
	}
	else {
		for (auto r : res) {
			if (r == 0)
				count--;
		}
		cout << count << " ";

		while (count != 0) {
			for (int k = res.size() - 1; k >= 0; --k) {
				if (count != 1) {
					if (res[k] == 0) {
						continue;
					}
					else {
						cout.flags(ios::fixed);
						cout.precision(1);
						cout << k << " " << res[k] << " ";
						count--;
					}
				}
				else {
					if (res[k] == 0)
						continue;
					else {
						cout.flags(ios::fixed);
						cout.precision(1);
						cout << k << " " << res[k];
						count--;
					}
				}
				
			}
		}
	}
	
	
	system("pause");
	return 0;

}
