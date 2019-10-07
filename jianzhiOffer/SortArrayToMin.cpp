//输入一个正整数数组，把数组中所有数字拼接起来排成一数，打印能拼接出的所有数字中最小的一个
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

int getdigit(int num) {
	int num_ = num;
	int n = 0;
	while (num_ != 0) {
		num_ /= 10;
		n++;
	}
	return n;
}


int getdigitofnum(int num, int i) { //n:digit of the num     return the i digit of the num
	if (i < 1)
		return 0;
	int n = getdigit(num);
	int n_, res;                    //n_: the digit from right to left of the num
	n_ = n - i + 1;
	res = num / (pow(10, n_ - 1));
	res = res % 10;
}

int compare_(int a, int b) {
	int ad = getdigit(a);
	int bd = getdigit(b);
	int d = ad > bd ? ad : bd;
	int i;
	int adi, bdi;
	for (i = 1; i <= d; ++i) {
		adi = getdigitofnum(a, i);
		bdi = getdigitofnum(b, i);
		if (adi < bdi) {
			return a;
		}
		else if (adi > bdi) {
			return b;
		}
	}
	if (ad >= bd) {
		return getdigitofnum(ad, i + 1) < getdigitofnum(ad, 1) ? a : b;
	}
	else {
		return getdigitofnum(bd, i + 1) < getdigitofnum(bd, 1) ? b : a;
	}
}

int sorttomin(vector<int> array) {
	if (array.size() == 0)
		return 0;
	auto asize = array.size();
	vector<int> res;
	for (int i = 0; i < asize; ++i) {
		int j = 0;
		int front = array[j];
		while (j != asize-1) {
			front = compare_(front, array[j + 1]);
			++j;
		}
		res.push_back(front);
	}
	string str;
	for (auto r : res) {
		str.push_back(r);
	}
}