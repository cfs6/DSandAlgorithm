//Get the number of 1 
int numberOf1(int n){
	int count;
	int flag = 1;
	while(flag){
		if(n&flag)
			++count;
		flag<<1;
	}
	return count;

}

//Another way
int numberOf1(int n){
	int count;
	while(n){
		n = n&(n-1);
		++count;
	}
	return count;
}
