//using sort method
#include<iostream>

void hasRepeatingNumber(int numbers[], int length, int reNumber[]){
	if(numbers ==nullptr||length<0)
		return 0;
	for(int i = 0; i<length; i++){
		if(numbers[i]<0||numbers[i]>length-1)
			return 0;
	}
	int j = 0;
	for(int i = 0; i < length; i++){
		while(i != numbers[i]){
			if(numbers[i]==numbers[numbers[i]]){
				reNumber[j] = numbers[i];
				numbers[i] = -1;        //to be reviewed      
				break;					//to be reviewed	  
			}
			int temp = numbers[i];
			numbers[i] = numbers[numbers[i]];
			numbers[numbers[i]] = temp;
		}
	}
}


