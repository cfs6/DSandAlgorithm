//Depth first search
template<typename T,typename E>
void DFS(Graph<T,E>& G, const T& v){
	int n = G.numberOfVertices;
	bool visited = new int(n);
	for(int i = 0; i < n; ++i)
		visited[i] = false;
	dfs(G, v, visited);

}

template<typename T, typename E>
void dfs(Graph<T, E>& G, const T& v, bool& visited[]){
	visited[v] = true;
	T w = G.getFirstNeighbor(v);
	while(w){
		if(!visited[w])
			dfs(G, w, visited);	
		w = G.getNextNeighbor(v, w);
	}
}
//另一种写法
template<typename T, typename E>
void dfs(Graph<T, E> G, const T &v, bool& visited[]){
	visited[v] = true;
	for(int w =G.firstNeighbor(v); w>-1; w = G.nextNeighbor(v)){
		if(!visited[w])
			dfs(G, w, visited);
	}
}


