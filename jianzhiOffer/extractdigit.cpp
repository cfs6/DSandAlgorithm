//将按 , 或 . 或大写字符ADF 等字符隔开的数字读取提取
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<string.h>
using namespace std;

int main() {
	string str = "AYE79 SONG 72A";
	vector<int> res;
	vector<string> strres;
	string str_ = str;
	for (int i = 0; i < str.length(); ++i) { //将不需要的间隔字符转为空格
		if (str_[i] <='0'||str[i]>='9')
			str_[i] = ' ';
	}
	stringstream ss(str_);                   //stringstream 以空格为读取界
	int temp;
	while (ss >> temp) {
		res.push_back(temp);
	}
	for (auto r : res) {
		cout << r << " ";
	}
	system("pause");
	return 0;
}
