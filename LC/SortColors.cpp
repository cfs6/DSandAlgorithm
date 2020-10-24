/*现在有一个包含n个物体的数组，其中物体颜色为颜色为红色、白色或蓝色，
请对这个数组进行排序，让相同颜色的物体相邻，颜色的顺序为红色，白色，蓝色。 
我们用0,1,2分别代表颜色红，白，蓝 
注意： 
本题要求你不能使用排序库函数 
扩展： 
一个非常直接的解法是两步的计数排序的算法 
首先：遍历一遍数组，记录0,1,2的数量，然后重写这个数组，先将0写入，
再将1写入，再将2写入 .
你能给出一个只用一步，并且能在常数级空间复杂度解决这个问题的算法吗？ */
/*设置3个变量，分别代表数组前部zeroindex，当前遍历的位置 i，数组后部 twoindex 
①当A[i] = 0时，必然属于数组前部，则交换A[i] 和 A[zeroindex] ,接着i++ , zeroindex++ 
②当A[i] = 1时，只需i++就好，因为只有排好了0和2,1自然就只能在中间了，故不作处理 
③当A[i] = 2时，不然属于数组后部，则交换A[i]和A[twoindex]，接着twoindex--，
不过此时就不能i++了因为，交换过去的A[i]有可能是0或者2，所以需要在下一个循环里判断，
这样它的位置才能够正确 */
#include<algorithm>
class Solution {
public:
	void swap(int& a, int& b)
	{
		int temp = b;
		b = a;
		a = temp;
	}

	void sortColors(int A[], int n) {
		int zeroIndex = 0, twoIndex = n - 1;
		int i = 0;
		while (i<=twoIndex)
		{
			if (A[i] == 0)
			{
				swap(A[i], A[zeroIndex]);
				i++;
				zeroIndex++;
			}
			else if (A[i] == 2)
			{
				swap(A[i], A[twoIndex]);
				twoIndex--;
			}
			else
			{
				i++;
			}
		}
	}
};