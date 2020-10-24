/*给出用数字数组表示的一个非负整数，请对该整数加1。*/
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	/**
	*
	* @param digits int整型vector
	* @return int整型vector
	*/
	//注意测试用例要全面包括所有情况
	bool carry = false;
	vector<int> plusOne(vector<int>& digits) {
		int vecSize = digits.size();
		int i = vecSize - 1;
		digits[i]++;
		if (10 == digits[i])
		{
			carry = true;
			digits[i] = 0;
		}
		--i;
		while (i >= 0 && carry)
		{
			digits[i]++;
			if (digits[i] == 10)
			{
				digits[i] = 0;
			}
			else
			{
				carry = false;
			}
			--i;
		}
		if (carry && i == -1)
		{
			digits.clear();
			digits.push_back(1);
			while (vecSize != 0)
			{
				digits.push_back(0);
				vecSize--;
			}
		}
		return digits;
	}
};