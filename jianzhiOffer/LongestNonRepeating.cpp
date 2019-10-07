//最长不含重复字符的子字符串
//返回子字符串
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int IsRepeating(string str, char c) {     
	int strlength = str.length();
	for (int i = 0; i < strlength; ++i) {
		if (str[i] == c)
			return i;
	}
	return -1;
}

string LongestNonRepeating(string s) {
	int slength = s.length();
	vector<char> res;
	res.push_back(s[0]);
	string maxstr;
	string sp(1,'0');
	sp[0] = s[0];
	maxstr = sp;
	for (int i = 1; i < slength; ++i) {
		int mark = IsRepeating(sp, s[i]);
		if (mark != -1) {
			sp = sp.substr(mark+1);
			sp.append(1, s[i]);
			cout <<"-1"<< sp << endl;
		}
		
		else {
			sp.append(1, s[i]);
			cout << sp << endl;
		}
		if (maxstr.length() < sp.length()) {
			maxstr = sp;
		}
	}
	return maxstr;
}
/*
int main() {
	string str = "arabcacfr";
	string res;
	res = LongestNonRepeating(str);
	cout << res;
	system("pause");
}
*/