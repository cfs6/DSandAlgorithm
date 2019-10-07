//ÅÅÁĞ/×éºÏ
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> res;

void swap(char s1, char s2) {
	char temp=s1;
	s1 = s2;
	s2 = temp;
}

void permutation(string str, int start, int end,vector<string>& res) {
	int strlength = str.length();
	if (start == end) {
		return;
	}
	res.push_back(str);
	for (int i = start; i < end; ++i) {
		swap(str[start], str[i]);
		permutation(str, start + 1, end, res);
		swap(str[start + 1], str[i]);
	}
	
}

int main() {
	string str = "faefes";
	permutation()
}