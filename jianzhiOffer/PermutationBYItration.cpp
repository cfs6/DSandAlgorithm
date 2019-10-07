//Permutation of the string by iteration
#include<string>
#include<vector>
#include<set>
#include<iostream>



void permutationCore(int a, std::string &str, std::set<std::string> &res) {
	int sLength = str.length();
	if (a > sLength - 1)
		return;
	res.insert(str);
	for (int i = a; i < sLength; ++i) {
		char temp = str[a];
		str[a] = str[i];
		str[i] = temp;
		res.insert(str);
		permutationCore(a + 1, str, res);
		temp = str[a];                     //需要恢复原次序，若不恢复可能会错过中间某位置，结果缺失 
		str[a] = str[i];
		str[i] = temp;
	}
}
void permutation(std::string s) {
	if (s.length() == 0 || s.length() == 1)
		return;
	std::set<std::string> resSet;
	permutationCore(0, s, resSet);
	for (auto r : resSet)
		std::cout << r << std::endl;
	//	std::cout << resSet.size();
}

int main() {
	std::string s = "abc";
	permutation(s);
	system("pause");
	return 0;
}
