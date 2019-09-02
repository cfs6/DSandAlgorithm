//search the digit in the 2D matrix

int searchIn2DMatrix(int* matrix, int rows, int coloums, int number){
	if(matrix==nullptr||rows<0||coloums<0)
		return -1;
	int r = 0;
	int c = coloum -1;
	while(matrix[r*rows+c]!=number&&r<rows&&c>=0){
		if(matrix[r*rows+c]>number){
			c--;
		}
		else{
			r++;
		}
	}
	if((matrix[r*rows+c]==number))
		return (r,c);
}
