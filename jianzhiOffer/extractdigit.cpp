//���� , �� . ���д�ַ�ADF ���ַ����������ֶ�ȡ��ȡ
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
	for (int i = 0; i < str.length(); ++i) { //������Ҫ�ļ���ַ�תΪ�ո�
		if (str_[i] <='0'||str[i]>='9')
			str_[i] = ' ';
	}
	stringstream ss(str_);                   //stringstream �Կո�Ϊ��ȡ��
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
