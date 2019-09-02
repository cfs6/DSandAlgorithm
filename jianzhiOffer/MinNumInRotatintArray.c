//Search the minimal number in the rotating array
int searchMinInRotatingArray(int num[], int low, int high){
	if(num == nullptr||low<0||high<0)
		return 0;
	int low =0;
	int high = num.size()-1;
	int mid = low;
	while(num[low]>=num[high]){
		if(low<=high-1)
			break;
		mid = (high-low)/2;
		if(num[low]==num[high]&&num[low]==num[mid])
			return searchInOrder(num,low,high);
		if(num[mid]>=num[low]){
			low = mid;
		}
		else if(num[mid]<=num[high]){
			high = mid;
		}

	}
	return high;
}

int searchInOrder(int num[], int low, int high){
	for(int i = 0; i < high-low-1; ++i){
		if(num[i]>num[i+1])
			return num[i+1];
	}
}
