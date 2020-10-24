//1005 Spell It Right
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	vector<int> digit;
	int d;

	int sLength = str.length();
	for (int i = 0; i < sLength;++i) {

		d = str[i] - '0';
		digit.push_back(d);
	}
	int count = 0;
	for (auto dp : digit) {
		count += dp;
	}

	string resStr;
	stringstream ss;
	ss << count;
	ss >> resStr;
	vector<string> res;
	string resNum;
	for (int k = 0; k < resStr.length(); ++k) {
		int dig = resStr[k] - '0';
		
		switch (dig)
		{
		case 0:
			resNum = "zero";
			break;
		case 1:
			resNum = "one";
			break;
		case 2:
			resNum = "two";
			break;
		case 3:
			resNum = "three";
			break;
		case 4:
			resNum = "four";
			break;
		case 5:
			resNum = "five";
			break;
		case 6:
			resNum = "six";
			break;
		case 7:
			resNum = "seven";
			break;
		case 8:
			resNum = "eight";
			break;
		case 9:
			resNum = "nine";
			break;
		case 10:
			resNum = "ten"; 
			break;
		case 11:
			resNum = "eleven";
			break;
		case 12:
			resNum = "twelve";
			break;
		default:
			break;
		}
		res.push_back(resNum);
	}
	for (int k = 0; k < res.size()-1; ++k)
		cout << res[k] << " ";
	cout << res[res.size()-1];
	system("pause");
}

