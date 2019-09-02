//Is the sequence the post traverse of a BST
bool isPostTravBST(int[] sequence, int length){
	if(sequence == nullptr || length <= 0)
		return false;
	bool isPost = true;
	int i = 0;
	while(i<length-1){
		if(sequence[i] > sequence[length-1])
			break;
		++i;
	}
	int[] leftBranch = new int[i];
	int leftLength = 0;
	for(int j = 0; j < i; ++j){
		leftBranch[j] = sequence[j];
		leftLength++;
	}
	int[] rightBranch = new int[length-i];
	int rightLength = 0;
	for(int j = i; j < length; ++j){
		rightBranch[j] = sequence[j];
		rightLength++;
	}
	for(int k = i; k < legnth; ++k){
		if(sequence[k] < sequence[length-1])
			isPost = false;
	}
	bool left = true;
	bool right = true;
	if(leftLength>0)
		left = isPostTravBST(leftBranch, leftLength);
	if(rightLength>0)
		right = isPostTravBST(rightBranch, rightLength);
	return isPost;
}
