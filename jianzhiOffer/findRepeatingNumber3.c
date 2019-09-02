//using binary search

int getDuplication(const int numbers[], int length){
	if(numbers == nullptr||length<0)
		return 0;
	int low = 1;
	int high = length-1;
	while(high>=low){
		mid = (high-low)>>2 + 1;
		lowNumbers = countNumber(numbsers, low, mid, length);
		if(high == low){
			if(count>1)
				return low;
			else
				return -1;
		}
		
			
		if(lowNumbers>(mid-start+1)){
			high = mid;
		}
		else{
			low = mid+1;
		}
	}
	return -1;
}

int countNumber(int numbers[], int low, int high, int length){
	int count;
	for(int i = 0; i < length; i++){
		if(numbers[i]>low&&numbers[i]<high)
			count++;
	}
	return count;
}