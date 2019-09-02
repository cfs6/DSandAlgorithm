
template<typename T>
void vector<T>::bubbleSort(int* m, int low, int high){
	while(low<high-1)
	{
		while(low < high){
			if(m[low]>m[low+1])
				swap(m[low], m[low+1]);
			low++;
		}
		high--;
		low = 0;
	}
}
