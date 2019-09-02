//数组中两数之差小于k才可配对，求最大可配对组数
int MaxMatch(int[] weight, int n, int k){
	if(weight==nullptr||n<=0||k<=0)
		return 0;
	qSort(weight, n, 0, n-1);
	int count;
	for(int i = 0; i < n; i+=2){
		if(abs(weight[i]-weight[i+1])<=k)
			count++;
	}
	return count;
}

void qSort(int[] weight, int n, int low, int high){
	if(high-low<=1)
		return;
	int q = weight[low];
	int p = weight[low+rand()%n];
	swap(weight[p], weight[q]);
	int pivot = weight[p];
	while(high>=low){
		while(weight[high]>pivot&&high>low){
			high--;
		}
			weight[p] = weight[high];
		while(weight[low]<pivot&&high>low){
			low++;
		}
			weight[high] = weight[low];
	}
	weight[low] = pivot;
	p = low;
	qSort(weight, p+1, 0, p);
	qSort(weight, high-p+1, p, high);
}
