//Print the matrix clockwise

void printMatrixClockwise(int[] matrix, int cols, int rows){
	if(matrix==nullptr||cols<=0||rows<=0)
		return;	
	int a = 0
	while(cols>0&&rows>0){
		printOuter(matrix, cols, rows, a);
		cols-=2;
		rows-=2;
		++a;
	}
}

void printOuter(int[][] matrix, int cols, int rows, int a){
	if(rows<=0||cols<=0)
		return;
	for(int m = a; m < cols; ++m){
		cout<<matrix[0][m]<<" ";
	}
	for(int n = a+1; n < rows; ++n){
		cout<<matrix[n][cols-1]<<" ";
	}
	for(int p = cols-1-1-a; p >= a; --p){
		cout<<matrix[rows-1][p]<<" ";
	}
	for(int q = rows-1-1-a; q > a; q--){
		cout<<matrix[q][0]<<" ";
	}
}
