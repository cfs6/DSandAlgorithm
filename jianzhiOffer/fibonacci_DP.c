//fibonacci polynominal by dynamic programming

long long Fibonacci(unsigned n){
	long long F0 = 0;
	long long F1 = 1;
	long long Fn;
	if(n < 0)
		return F0;
	else if(n = 0)
		return F0;
	else if(n = 1)
		return F1;
	else{
		for(int i = 2; i < n; i++){
			Fn = F0 + F1;
			F0 = F1;
			F1 = Fn;
		}
	}
	return F1;
}
