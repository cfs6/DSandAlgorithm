/*����һ�������һ��ֵ��ʹ�þ͵��㷨�����������е������ֵ��Ԫ��ɾ����������������ĳ��ȡ�

Ԫ�ص�˳����Ը��ġ��㲻��ȥ���Ĵ��ڵ�ǰ���鳤�ȵĿռ�����洢��ֵ*/
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		if (n == 0)
			return 0;
		for (int i = 0; i < n; ++i)
		{
			if (A[i] == elem)
			{
				swap(A[i], A[n - 1]);     //�����һλ����������Ҫ�ƶ������Ԫ�أ�Ч�ʸ���
				n--;
				--i;
			}
		}
		return n;
	}
};