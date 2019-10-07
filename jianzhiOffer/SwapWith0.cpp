/**
* ����������n��0��λ��
* array: �洢[0-n)������
* len: ���鳤��
* n: ������Ҫ��0��������
*/
extern void swap_with_zero(int* array, int len, int n);

class Solution {
public:
	/**
	* ���÷���swap_with_zero����array��������
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