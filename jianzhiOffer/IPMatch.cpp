#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int findstar(string s) {
	int slength = s.length();
	int mark = 0;

	while (mark != slength) {  
		if (s[mark] == '*') {
			return mark;
		}
		else {
			mark++;
		}
	}
	return -1;
}

bool isMatch(string s1, string s2) {
	int mark = findstar(s1);
	int s2length = s2.length();
	int s1length = s1.length();
	cout << mark << " " << s1length << endl;
	for (auto a : s1) {
		cout << a;
	}
	cout << endl;
	if (mark == -1) {
		return s1 == s2;
	}
	else if(mark==0){                    //多参数写清楚
		int k1 = s1length - 1;
//		int k2 = k - (s2length - s1length);
		int k2 = s2length - 1;
		for (; k1 > 1; --k1, --k2) {
			if (s2[k2] != s1[k1]) {
				return false;
			}
		}
		return true;
	}
	else if (mark == (s1length - 1)) {
		for (int i = 0; i < mark; ++i) {
			if (s2[i] != s1[i]) {
				return false;
			}
		}
	}
	return true;

}

vector<int> getvec(string str) {
	stringstream ss(str);
	vector<int> sint;
	int tem;
	while (ss >> tem) {
		sint.push_back(tem);
	}

	return sint;
}
int main() {
	int m, n;
	string str;
	getline(cin, str);
	vector<int> sint = getvec(str);
	n = sint[0];
	m = sint[1];
	vector<string> str1(n);
	vector<string> str2(m);
	vector<int> res;
	
	for (int i = 0; i < n; ++i) {
		getline(cin, str1[i]);
	}
	for (int j = 0; j < m; ++j) {
		getline(cin, str2[j]);
	}
/*
	for (auto st : str1) {
		cout << st<<endl;
	}
	for (auto st2 : str2) {
		cout << st2 << endl;
	}
	*/
	bool r;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			r = isMatch(str1[j], str2[i]);
			if (r == true)
				break;
		}
		if (r)
			res.push_back(1);
		else
			res.push_back(0);
	}

	for (auto r : res) {
		cout << r << " ";
	}
	system("pause");
}


/*
5 3
222.205.58.16
*.58.16
222.205.58.*
*.16
224.*
222.205.58.17
222.205.59.19
223.205.59.16 
*/

