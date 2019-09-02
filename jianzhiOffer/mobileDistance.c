//caculate the way of robot move
#include<queue>
using namespace std;

int movingWay( int k, int m, int n){
	if(matrix == nullptr||k<0||m<0||n<0)
		return 0;
	bool* visited = new bool[m*n];
	for(int i = 0; i < m*n; ++i)
		visited = false;
	int res = move(0, 0, matrix, m, n, k, visited);
	delete visited[];
	return res;
}

int move(int row, int col, int m, int n, int k, bool& visited[]){
	visited[row*m+col*n] = true;
	queue<int> Cqueue;
	Cqueue.enqueu(row*m+n);
	int* w = new int[4];
	while(!Cqueue.empty()){
		int u = dequeue();
		if((row+1<=rows)&&((row/10+row%10+col/10+col%10)<=k))
			w[0] = (row+1)*m+col*n;
		else
			w[0] = -1;
		if((row-1>=0)&&((row/10+row%10+col/10+col%10)<=k))
			w[1] = (row-1)*m+col*n;
		else
			w[1] = -1;
		if((col+1<=cols)&&((row/10+row%10+col/10+col%10)<=k))
			w[2] = row*m+(col+1)*n;
		else
			w[2] = -1;
		if((col-1>=0)&&((row/10+row%10+col/10+col%10)<=k))
			w[3] = row*m+(col-1)*n;
		else
			w[3] = -1;
		for(auto &w_per : w){
			if((!visited[w_per])&&(w!=-1)){
				visited[w_per] = true;
				Cqueue.enqueue(w_per);	
			}
		}
	}
	int count;
	for(auto &vis : visited){
		if(visited[vis]==true)
			count++;
	}
	return count;
}



