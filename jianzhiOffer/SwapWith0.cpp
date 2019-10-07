/**
* 交换数组里n和0的位置
* array: 存储[0-n)的数组
* len: 数组长度
* n: 数组里要和0交换的数
*/
extern void swap_with_zero(int* array, int len, int n);

class Solution {
public:
	/**
	* 调用方法swap_with_zero来对array进行排序
	*/
	void sort(int* array, int len) {
		int length = len;
		while (length != 0) {
			swap_with_zero(array, len, array[0]);
			for (int i = 1; i < length - 1; ++i) {
				if (array[i] > array[length - 1]) {
					swap_with_zero(array, len, array[length - 1]);
					swap_with_zero(array, len, array[i]);
				}
			}
			length--;
		}
	}
};