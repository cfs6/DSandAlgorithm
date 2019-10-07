#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

int main() {
	long long a, b;
	long long sum, sumcopy;
	vector<int>res;
	cin >> a >> b;
	sum = a + b;
	bool isnegative = false;
	if (sum < 0)
		isnegative = true;
	sum = abs(sum);
	int remain = sum % 1000;
	int count=0;
	sumcopy = sum;
	while (sumcopy / 1000 != 0) {
		count++;
		sumcopy = sumcopy / 1000;
	}
	stringstream ss;
	string str;
	ss << sum;
	ss >> str;
	int slength = str.length();

	for (int i = slength - 1; i-2 > 0; ) {
		i -= 2;
		str.insert(i, ",");
		i--;
	}
	if (isnegative) {
		cout << "-";
	}
	cout << str;
	system("pause");
}