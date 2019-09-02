//Reorder the odd to front of the even in the matrix
void ReorderOddEven(int* numbers, int length){
	if(numbers == nullptr||length<=0)
		return;
	int i = 0;
	int j = length-1;
	int temp;
	while(i<j){
		while(numbers[i]&0x1!=0)
			++i;
		while(numbers[j]&0x1!=1)
			++j;
		if(i<j){
			temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;
		}
	}
}
