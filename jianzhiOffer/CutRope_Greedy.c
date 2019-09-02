//Cut the rope by greedy algorithm
int cutRope_Greedy(int length){
	if(length < 2)
		return 0;
	if(length == 2)
		return 1;
	if(length == 3)
		return 2;
	int max = 1;
	int timeOf3 = length / 3;
	if(length%3 == 1){
		timeOf3 -= 1;
		max *= 4;
	}
	for(int i = 0; i < timeOf3; ++i){
		max *= 3;
	}
	return max;
	

}
