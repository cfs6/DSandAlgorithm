//在字符串中找到第一个只出现一次的字符
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

char findnotrepeating(string str) {
	int strlength = str.length();
	map<char,int> strmap;
	
	for (int i = 0; i < str.length(); ++i) {
//		cout << str[i] << " ";
		++strmap[str[i]];
	}
	
	for (int j = 0; j < str.length(); ++j) {
		if (strmap[str[j]] == 1)
			return str[j];
	}
	
}
/*
int main() {
	string str = "afsaicnvsokemcsadssoenmoimekjsragex";
//	cout << str << endl;
	char c = findnotrepeating(str);
	cout << c << endl;
	system("pause");
	return 0;
}
*/

//Another way
//o(1)空间，需要自定义数组作为哈希表
char FirstNotRepeating(char* pString) {
	if (pString == nullptr)
		return '\0';
	char* pStr = pString;
	const int tablesize = 256;
	unsigned int hashtable[tablesize];
	for (unsigned int i = 0; i < tablesize; ++i) {
		hashtable[i] = 0;
	}

	while (*pStr != '\0') {
		hashtable[*(pStr++)]++;
	}

	pStr = pString;
	while (pStr != '\0') {
		if (hashtable[*pStr] == 1)
			return *pStr;
		pStr++;
	}
	return '\0';
}
