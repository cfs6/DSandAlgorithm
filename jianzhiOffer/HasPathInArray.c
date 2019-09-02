//judge if there is a path in the array
bool hasPath(char *matrix, int cols, int rows, char* str){
	if(matrix == nullptr||str == nullptr||cols<=0||rows<=0)
		return 0;
	bool *visited = new bool[rows*cols];
	int pathLength = 0;
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			if(searchPath(matrix, cols, rows, i, j, visited, str, pathlength))
				return true;
		}
	}
	delete []visited;
	return false;
}

bool searchPath(char* matrix, int cols, int rows, int col, int row, bool* visited,const char* str, int& pathLength){
	if(str[pathLength] == '\0')
		return;
	bool hasPath = false;
	if(col>=0&&col<cols&&row>=0&&row<rows&&matrix[row*cols+col]==str[pathLength]&&!visited[row*cols+col]){
		pathLength++;
		visited[row*cols+col] = true;
		hasPath = searchPath(matrix, cols, rows, col+1, row, visited, str, pathLength)||
		searchPath(matrix, cols, rows, col, row+1, visited, str, pathLength)||
		searchPath(matrix, cols, rows, col-1, row, visited, str, pathLength)||
		searchPath(matrix, cols, rows, col, row-1, visited, str, pathLength);
		if(!hasPath){
			pathLength--;
			visited[row*cols+col] = false;
		}
	}
	return hasPath;
}


