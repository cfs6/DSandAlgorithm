//0~n-1��ȱʧ������
//���������л��ڶ��ֲ�������
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
	if (start == length)                        //��ѭ������δ�ҵ�Ŀ�꣬���ʱstartΪlength��Ϊ����
		return length;
	return -1;
}