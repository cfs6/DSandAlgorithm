#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int main() {
	float start, end;
	int n;
	vector<float> res;
	cin >> start >> end >> n;
	if (n <= 1) {
		cout << 0;
	}
	else {
		if (start>end) {
			float c = start - end;
			float interv = c / (n - 1);
			int t = 0;
			while (t != n - 1) {
				float s;
				for (int i = 1; i <= 3; ++i) {
					if (t == n - 1)
						break;
					s = start - i*interv;
					res.push_back(s);
					++t;
				}
			}
		}
		else {
			float c = end - start;
			float interv = c / (n - 1);
			int t = 0;
			while (t != n - 1) {
				float s;
				for (int i = 1; i <= 3; ++i) {
					if (t == n - 1)
						break;
					s = start + i*interv;
					res.push_back(s);
					++t;
				}
			}
		}
		for (int k = 0; k<res.size() - 1; ++k) {
			cout << setiosflags(ios::fixed) << setprecision(2) << res[k] << ",";
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << res[res.size() - 1];
	}
	system("pause");
}