// Cut the rope to pieces
int cutRope(int length){
	if(length <= 1)
		return 0;
	if(length == 2)
		return 1;
	if(length == 3)
		return 2;
	int* res = new int[length];
	res[1] = 1;
	res[2] = 2;
	res[3] = 3;
	int max = 0;
	for(int i = 4; i<=length; ++i){
		max=0;
		for(int j = 1; j <= i/2; ++j){
			int res = res[j] * res[i-j];
			if(res>max)
				max = res;
		}
		res[i] = max;
	}
	max = res[length];
	delete[] res;
	return max;
}
