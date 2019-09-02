//sort finite number in small range

#include<vector>

void SSort(int num[], length){
	if(num == nullptr|| length<=0)
		return 0;
	int sortNum[length+1];
	int n;
	for(int k = 0; k<length+1;k++)
		sortNum[k] = 0;
	for(int i = 0; i<num.size(); i++){
		n = num[i];
		sortNum[n]++;
	}
	int index = 0;
	for(int p = 0; p < length; p++){
		for(int k = 0; k < sortNum[p]; k++ ){
			num[index] = p;
			index++;
		}
	}
}
