template<typename T>
void vector<T>::mergeSort(int low, int high){
	if(high-low <2){
		if(M[low]>M[high])
			swap(M[low],M[high]);
		return;
	}
	int mid = (low + high)/2;
	mergeSort(low, mid);
	mergeSort(mid+1, high);
	merge(low, mid, high);

}
template<typename T>
void merge(int low, int mid, int high){
	vector<T> newM;
	int k = mid+1;
	while(low<=mid||k<=high){
		if(M[low]<=M[k]){
			newM.pushback(M[low]);
			low++;
		}
		else{
			newM.pushback(M[k]);
			k++;
		}
	}
	if((low>mid)&&(k<=high)){
		while(k<=high){
			M.pushback(M[k]);
			k++;
		}
	}
	if((low<=mid)&&(k>high)){
		while(low<=mid){
			M.pushback(M[low]);
			low++;
		}

	}

}
