/*继续思考题目"Remove Duplicates": 
如果数组中元素最多允许重复两次呢？ 
例如： 
给出有序数组 A =[1,1,1,2,2,3], 
你给出的函数应该返回length =5,  A 变为[1,1,2,2,3].*/
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