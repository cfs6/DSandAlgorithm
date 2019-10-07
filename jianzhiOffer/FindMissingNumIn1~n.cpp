//0~n-1中缺失的数字
//排序数组中基于二分查找搜索
int GetMissingNum(const int* array, int length) {
	if (array == nullptr||length<=0)
		return -1;
	int start = 0;
	int end = length - 1;
	int res;
	while (start <= end) {
		int mid = (end + start) / 2;            //!!
		if (array[mid] == mid) {
			start = mid + 1;
		}
		else {
			if (array[mid - 1] == mid - 1) {
				return mid;
			}
			else {
				end = mid - 1;
			}
		}
	}
	if (start == length)                        //若循环结束未找到目标，则此时start为length即为所求
		return length;
	return -1;
}