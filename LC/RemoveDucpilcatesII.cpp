/*����˼����Ŀ"Remove Duplicates": 
���������Ԫ����������ظ������أ� 
���磺 
������������ A =[1,1,1,2,2,3], 
������ĺ���Ӧ�÷���length =5,  A ��Ϊ[1,1,2,2,3].*/
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (A == nullptr || n <= 2)
			return n;
		int duplicatesCount = 2;
		for (int i = 2; i < n; ++i)
		{
			if (A[i] != A[i - 2])
			{
				A[duplicatesCount++] = A[i];
			}
		}
	}
};