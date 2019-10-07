//translate number to sting
//0:a  1:b  ...  25:z
//返回一个数字有多少种不同的翻译方法
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

vector<int> splitnum(int num) {
	vector<vector<int>> r;
	vector<int> digit;

	int count = 0;
	int n = num;
	while (n != 0) {
		n /= 10;
		count++;
	}
	for (int i = count; i>0; --i) {
		int d = num / (pow(10, i - 1));
		if (d / 10 == 0) {
			digit.push_back(d);
		}
		else {
			d = d % 10;
			digit.push_back(d);
		}
	}
	return digit;
}

vector<vector<int>> CombineNum(vector<int> num) {
	int numsize = num.size();
	vector<vector<int>> res;
	vector<int> r;
	bool isvisit;
	for (int i = 0; i < numsize-1; ++i) {
		int d = num[i] * 10 + num[i + 1];
		r.clear();
		if (d<26&&d>=10) {
			for (int j = 0; j < numsize - 1; ++j) {
				if (j == i) {
					r.push_back(d);
					j++;
				}
				else {
					r.push_back(num[j]);
				}
			}
		}
		res.push_back(r);
	}
}


vector<int> TransNumToStr(int num) {             // main function
	vector<int> res;
	vector<char> resc;
	string slist = "abcdefghijklmnopqrstuvwxyz";
	res = splitnum(num);
	

}




//Another way by DP
//Transform the number from right to left
//count only

int GetTranslationCount(int num) {
	if (num < 0)
		return 0;
	string numstr = to_string(num);
	return GetTranslationCountCore(numstr);
}

int GetTranslationCountCore(string numstr) {
	int strlength = numstr.length();
	int count;                              //count:每一步(i)的计数
	int* counts = new int[strlength];       //counts[]:计数记录
	for (int i = strlength - 1; i >= 0; --i) {
		count = 0;
		if (i < strlength - 1)
			count = counts[i];
		else
			count = 1;
		if (i < strlength - 1) {
			int digit1 = numstr[i] - '0';
			int digit2 = numstr[i + 1] - '0';
			int d = digit1 * 10 + digit2;
			if (d >= 10 && d <= 25) {
				if (i < strlength - 2)
					count += counts[i + 2];
				else
					count += 1;
			}
		}
		counts[i] =count;
	}
	count = counts[0];
	delete[] counts;
	return count;

}