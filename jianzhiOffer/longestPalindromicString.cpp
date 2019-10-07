//Longest palindromic string
#include<iostream>
#include<string>
#include<vector>
bool isPalindromic(std::string s);

std::string longestPalindromicString(std::string s) {
	std::string res;
	int strCount = 0;
	int strLength = s.length();
	for (int i = 2; i <= strLength; ++i) {
//		for (int m = 1; m < i; ++m) {
			for (int n = 0; n <= strLength - i; ++n) {
				std::string strNew(s, n, i);
	//			strNew.assign(s, n, i);
				if (isPalindromic(strNew)==true) {
					res.assign(strNew);
					if (strNew.length() == 2) {
						if (strNew[0] == strNew[1]) {
							res.assign(strNew);
							break;
						}
						else {
							res.assign(strNew, 0, 1);
						}
					}
					if(res.length()>2)
						break;
				}
			}
//		}
	}
	return res;
}

bool isPalindromic(std::string s) {
	int p1 = 0;
	int p2 = 0;
	int sLength = s.length();
	if (sLength == 2) 
		return true;
	if ((sLength & 1) == 0) {       //Range:s:0->p1    sNew:p1+1->p2+1
		while (p2+1 < sLength-1) {
			p1 += 1;
			p2 += 2;
		}
		std::string sNew;
//		int j = p2 - p1; //后半string翻转后的尾标
		for (int i = p2+1; i >= p1+1; --i) {
			sNew.insert(sNew.size(), 1, s[i]);
		}
		for (int k = 0; k <= p1; ++k) {
			if (s[k] != sNew[k])
				return false;
		}
		return true;
	}
	else {
		while (p2 < sLength-1) {    //Range:s:0->p1  sNew: p1->p2
			p1 += 1;
			p2 += 2;
		}
		std::string sNew;
//		int j = p2 - p1;
		for (int i = p2; i >= p1; --i) {	
			sNew.insert(sNew.size(), 1, s[i]);
		}
		for (int k = 0; k <= p1; ++k) {
			if (s[k] != sNew[k])
				return false;
		}
		return true;
	}
}

