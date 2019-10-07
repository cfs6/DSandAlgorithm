//输入一个字符串,按字典序打印出该字符串中字符的所有排列。
//例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
//动态规划方法
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


void addchar(char c, vector<string> &res) {
	vector<string> res2 = res;
	int ressize = res2.size();
	int strlength = res2[0].length();
	res.clear();

	for (int i = 0; i<ressize; ++i) {
		for (int j = 0; j<=strlength; ++j) {
			string pres = res2[i];
			pres.insert(j, 1, c);
			res.push_back(pres);
		}
//		for (auto r : res) {
//			cout << r<<" ";
//		}
		cout << endl;
	}
}

int main() {
	string str;
	getline(cin, str);
	vector<string> resv;
	int strlength = str.length();
	string newstr1(str, 0, 1);
	resv.push_back(newstr1);
//	for (auto re : resv)
//		cout << re<<endl;
	for (int i = 1; i<strlength; ++i) {
		addchar(str[i], resv);
	}
/*
	set<string> resset;
	for (int i = 0; i<resv.size() - 1; ++i) {
		resset.insert(resv[i]);
	}
	*/
//	cout << resset[resset.size() - 1];
	vector<string>::iterator it1;
	vector<string>::iterator it2;
	for (it1 = ++resv.begin(); it1 != resv.end();) {
		it2 = find(resv.begin(), it1, *it1);
		if (it1 != it2)
			it1 = resv.erase(it1); 
		else
			it1++;
	}
	sort(resv.begin(), resv.end());

	for (int i = 0; i<resv.size() - 1; ++i) {
		cout << resv[i] << ", ";
	}
	cout << resv[resv.size() - 1]<<endl;
	cout << resv.size() << endl;
	system("pause");
}
