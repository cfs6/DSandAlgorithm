/*����һ������������飬ʹ�þ͵��㷨���ظ��������Ƴ���
ʹ�����е�ÿ��Ԫ��ֻ����һ�Σ�����������ĳ��ȡ� 
����Ϊ����������Ŀռ䣬�����ʹ�ó��켶�ռ临�Ӷȵľ͵��㷨�� 
���磬
������������ A=[1,1,2]��
������ĺ���Ӧ�÷���length=2��A����������[1,2]��*/
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

//˫ָ�뷨
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