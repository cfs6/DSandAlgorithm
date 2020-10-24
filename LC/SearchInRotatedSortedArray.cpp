/*����һ��ת�������������飬�����Ȳ�֪��������ת���˶���
(����,0 1 2 4 5 6 7���ܱ�Ϊ4 5 6 7 0 1 2).
������������������Ŀ��ֵ����������������ҵ��������������������򷵻�-1��
���������в������ظ��*/
class Solution {
public:
	/**
	*
	* @param A int����һά����
	* @param n int A���鳤��
	* @param target int����
	* @return int����
	*/
	int search(int* A, int n, int target) {
		int first = 0;
		int last = n - 1;
		while (first <= last)
		{
			int mid = (last - first) / 2 + first;
			if (A[mid] == target)
				return mid;
			if (A[first] < A[mid])  //�������,���������ж��ֲ���
			{
				if (target >= A[first] && target < A[mid])
				{
					last = mid - 1;
				}
				else
				{
					first = mid + 1;
				}
			}
			else                    //�Ҳ����������Ҳ���ж��ֲ���
			{
				if (target > A[mid] && target <= A[last])
				{
					first = mid + 1;
				}
				else
				{
					last = mid - 1;
				}
			}
		}
		return -1;
	}
};
