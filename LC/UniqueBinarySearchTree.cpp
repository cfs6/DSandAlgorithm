//����һ��ֵn���ܹ��������ٲ�ͬ��ֵ����1...n�Ķ�����������BST����
class Solution {
public:
	/**
	*
	* @param n int����
	* @return int����
	*/
	/*���Ǹ��ڵ㣬�����������ڵ�k����f(k)�����Ŀ��ܡ�
    ��kС��k-1��Ԫ�ع���k��������������������f(k-1)�������
    ��k���n-k��Ԫ�ع���k��������������������f(n-k)�������
    ��֪�����������໥����������f(k)=f(k-1)*f(n-k)��*/
	//����dp������С�������res[]
	int numTrees(int n) {
		if (n == 0)
			return 1;
		int* res = new int[n + 1];
		res[0] = 1;
		res[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			res[i] = 0;
			for (int j = 1; j <= i; ++j)
			{
				res[i] += res[j - 1] * res[i - j];
			}
		}
		return res[n];
	}
};