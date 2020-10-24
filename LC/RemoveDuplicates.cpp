/*给定一个已排序的数组，使用就地算法将重复的数字移除，
使数组中的每个元素只出现一次，返回新数组的长度。 
不能为数组分配额外的空间，你必须使用常熟级空间复杂度的就地算法。 
例如，
给定输入数组 A=[1,1,2]，
你给出的函数应该返回length=2，A数组现在是[1,2]。*/
#include<iostream>
using namespace std;
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (A == nullptr || n <= 1)
			return n;
		int duplicateCount = 1;
		for (int i = 1; i < n; ++i)
		{
			if (A[i] != A[i - 1])
				A[duplicateCount++] = A[i];
		}
		return duplicateCount;
	}
};

//双指针法
int removeDuplicates(int A[], int n) {
	if (A == nullptr || n <= 1)
		return n;
	int i=0;
	bool twiceDup = false;
	for (int j = i+1; j < n; ++j)
	{
		if (A[i] == A[j] && !twiceDup && j<n)
		{
			++i;
			++j;
			twiceDup = true;
		}
		if (A[i] != A[j])
		{
			A[++i] = A[j];
			twiceDup = false;
		}
			
	}

	return ++i;
}
int main()
{
	int a[] = { 1,1,2,3 };
	Solution sol;
	int res = sol.removeDuplicates(a, 3);
	cout << res << endl;
}