//49.Ugly Number
#include<iostream>
#include<vector>
using namespace std;

bool IsUglyNum(int num) {
	while (num % 2 == 0) {
		num /= 2;
	}
	while (num % 3 == 0) {
		num /= 3;
	}
	while (num % 5 == 0) {
		num /= 5;
	}
	return (num == 1 ? true : false);
}

int GetUglyNum(int index) {
	if (index < 0)
		return 0;
	int number = 0;
	int count = 0;
	while (count != index) {
		number++;
		if (IsUglyNum(number))
			count++;
	}

	return number;
}

//Another way
//从小到大计算所有丑数，按顺序放入数组
//相对于第一种方式，不需要在非丑数上计算
int min(int num1, int num2, int num3) {
	int minnum = (num1 < num2) ? num1 : num2;
	return (minnum < num3) ? minnum : num3;
}

int GetUglyNum(int index) {
	if (index <= 0)
		return 0;


	int* pUglyNum = new int[index];
	pUglyNum[0] = 1;
	int nextUglyNum = 1;


	int* pMultiple2 = pUglyNum;
	int* pMultiple3 = pUglyNum;
	int* pMultiple5 = pUglyNum;

	while (nextUglyNum < index) {
		int minnum = min(*pMultiple2 * 2, *pMultiple3 * 3, *pMultiple5 * 5);
		pUglyNum[nextUglyNum] = minnum;
		while (*pMultiple2 * 2 <= minnum)
			pMultiple2++;
		while (*pMultiple3 * 3 <= minnum)
			pMultiple3++;
		while (*pMultiple5 * 5 <= minnum)
			pMultiple5++;
		nextUglyNum++;
	}

	int uglyNum = pUglyNum[index - 1];
	delete[] pUglyNum;
	pUglyNum = nullptr;

	return uglyNum;

}
