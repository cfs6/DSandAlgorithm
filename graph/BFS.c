//Broad first search
#include<queue>
template<typename T, typename E>
void BFS(Graph<T, E> G, int v){
	int n = G.getVerticesNumber();
	bool* visited = new bool[n];
	do{
		if(!visited[v])
			bfs(G, v);
	}while(s!=(v=(++v%n));
}

template<typename T, typename E>
void bfs(Graph<T, E> G, int v){
	queue<int> GQueue;
	int u;
	visited[v] = true;
	GQueue.enqueue(v);
	while(!GQueue.empty()){
		v = GQueue.enqueue();
		for(int u = firstNerghbor(v); u>-1; u = nextNeighbor(v)){
			if(!visited[u]){
				visited[u] = true;
				GQueue.enqueue(u);
			}
		}
	}
}
