//Quick sort
#include<vector>
template<typename T>
int partition(int* elem, int lo, int hi){
	swap(elem[lo], elem[lo + rand()%(hi - lo +1)]);
	T p = elem[lo];
	while(lo<high){
		while((lo<hi)&&(elem[hi]>=p)){
			hi--;
			elem[lo] =  elem[hi];
		}
		while((lo<hi)&&(elem[lo]<=p)){
			lo++;
			elem[hi] = elem[lo];
		}
	}
	elem[lo] = p;
	return lo;
}

template<typename T>
void quickSort(int* elem, int lo, int hi){
	if(elem == nullptr||lo<0||hi<0)
		return 0;
	if(lo>hi)
		return;
	int mi = partition(elem, lo, hi);
	quickSort(elem, lo, mi);
	quickSort(elem, mi+1, hi);
}
