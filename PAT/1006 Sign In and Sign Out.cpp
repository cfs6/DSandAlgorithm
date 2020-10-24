//1006 Sign In and Sign Out
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isEarlier(string str1, string str2) {
	vector<int> num1;
	vector<int> num2;
	int num;
	for (int i = 0; i < str1.length(); ++i) {
		if (str1[i] != ':') {
			num = str1[i] - '0';
			num1.push_back(num);
		}
	}
	for (int j = 0; j < str2.length(); ++j) {
		if (str2[j] != ':') {
			num = str2[j] - '0';
			num2.push_back(num);
		}
	}
	for (int k = 0; k < num1.size(); ++k) {
		if (num1[k] < num2[k])
			return true;
		else if (num1[k] > num2[k])
			return false;
	}
}
bool isLater(string str1, string str2) {
	vector<int> num1;
	vector<int> num2;
	int num;
	for (int i = 0; i < str1.length(); ++i) {
		if (str1[i] != ':') {
			num = str1[i] - '0';
			num1.push_back(num);
		}
	}
	for (int j = 0; j < str2.length(); ++j) {
		if (str2[j] != ':') {
			num = str2[j] - '0';
			num2.push_back(num);
		}
	}
	for (int k = 0; k < num1.size(); ++k) {
		if (num1[k] > num2[k])
			return true;
		else if (num1[k] < num2[k])
			return false;
	}
}


int main() {
	int m;
	cin >> m;
	if (m == 0) {
		cout << "0";
		return 0;
	}
	string strID;
	string strIn;
	string strOut;
	vector<pair<string,string>> timeIn;
	vector<pair<string, string>> timeOut;
	while (m != 0) {
		cin >> strID;
		cin >> strIn;
		cin >> strOut;
		pair<string,string> IDIn = make_pair(strID, strIn);
		pair<string, string> IDOut = make_pair(strID, strOut);
		timeIn.push_back(IDIn);
		timeOut.push_back(IDOut);
		m--;

	}

	int firstIn;
	int lastOut;
	int i, j;
	for (firstIn = 0,i = 1; i < timeIn.size(); ++i) {
		if (isEarlier(timeIn[i].second, timeIn[firstIn].second))
			firstIn = i;
		
	}
	cout << timeIn[firstIn].first << " ";

	for (lastOut = 0,j = 1; j < timeOut.size(); ++j) {
		if (isLater(timeOut[j].second, timeOut[lastOut].second))
			lastOut = j;
		
	}
	cout << timeOut[lastOut].first;

	system("pause");
}