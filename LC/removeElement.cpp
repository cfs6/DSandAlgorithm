/*给定一个数组和一个值，使用就地算法将数组中所有等于这个值的元素删除，并返回新数组的长度。

元素的顺序可以更改。你不用去关心大于当前数组长度的空间里面存储的值*/
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
				swap(A[i], A[n - 1]);     //与最后一位交换，不需要移动大多数元素，效率更高
				n--;
				--i;
			}
		}
		return n;
	}
};