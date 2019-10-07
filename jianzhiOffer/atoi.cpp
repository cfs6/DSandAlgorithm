//Convert str to int
//return 0 when input error
#include<iostream>
#include<cstdlib>
int atoi_(char* str) {
	int res = 0;
	bool isMinus = false;
	if (*str == ' ') //首字符允许空格，进一位
		str++;
	if (*str == '-' || *str == '+') {
		if (*str == '-')
			isMinus = true;
		str++;
	}
	//	else if (*str < '0' || *str > '9') {
	//		return 0;
	//	}
	while (*str != '\0') {
		if (*str > '0' && *str < '9') {
			res = res * 10 + *str - '0';
			++str;
		}
		else
			return 0;
	}

	return isMinus ? res*(-1) : res;
}



int main() {
	char* str = " +-24314124";
	int r = atoi_(str);
	std::cout << r << std::endl;
	system("pause");
	return 0;
}