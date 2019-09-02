
const int Defaultsize = 10;// 
class UFSets{
public:
	UFSets(int sz = Defaultsize);
	~UFSets(){delete []parent;}
	void Union(int root1,int root2);
	int Find(int x);
	void WeightedUnion(int root1, int root2);
	int CollapsingFind(int i);
private:
	int* parent;
	int size;
};

UFSets::UFSets(int sz){
	size = sz;
	parent = new int[sz];
	for(int i = 0; i < sz; i++)
		parent[i] = -1;
}

int UFSets::Find(int x){
	while(parent[x]>0)
		x = parent[x];
	return x;
}

void UFSets::Union(int root1, int root2){
	parent[root1] += parent[root2];
	parent[root2] = root1;
}

void UFSets::WeightedUnion(int root1, int root2){
	int r1 = Find(root1);
	int r2 = Find(root2);
	if(r1!=r2){
		if(parent[r]<parent[r2]){
			parent[r2] = r1;
			parent[r1] += parent[r2];
		}
		else{
			parent[r1] = r2;
			parent[r2] += parent[r1];
		}
	}
}

int UFSets::ColapasinFind(int i){
	for(int j = i;parent[j]>0;j++){
	}
	while(i!=j){
		int temp = parent[i];
		panrent[i] = j;
		i = temp;
	}
	return i;

}
