#include<Dich.h>
#define lazyRemoval(x) (lazyRemoval->test(x))
#define markAsRemoved(x) (lazyRemoval->set(x)
template<typename K, template V>
class HashTable: public Dictionary<K, V>{
private:
	Entry<K, V> **table;
	int M;//the capacity of table
	int N;//the capacity of entry
	Bitmap* lazyRemoval;
    

protected:
	int probe4Hit(const K& k);//find the mathced bucket of entry
	int probe4Free(const K& k);//find the free bucket of entry
	void rehash();
public:
	HashTable(int c = 5);
	~HashTable();
	int size()const = 0;
	bool put(K, V);
	V* get(K k);
	bool remove(K, V);
	int primeNLT(int c, int n, char* file);//get the prime number in the range of[c, n)
}

template<typename K,typename V>
int HashTable<K, V>::primeNLT(int c, int n, char* file){
	Bitmap B(file, n);
	while(c < n){
		if(B.test(c))
			return c;
		else
			c++;
	}
	return c;
}

template<typename K,typename V>
HashTable<K, V>::HashTable(int c){
	M = primeNLT(0, c, "filepath");
	N = 0;
	table = new Entry<K, V>*[M];
	memset(table, 0, sizeof(Entry<K, V>*)*M);
	lazyRemoval = new Bitmap(M);
}

template<typename K,typename V>
HashTable<K, V>::~HashTable(){
	for(int i=0; i<M; ++i){
		if(table[i])
			release(table[i]);
	}
	release(table);
	release(lazyRemoval);
}

template<typename K,typename V>
V* HashTable<K, V>::get(K k){
	int r = probe4Hit(K& k);
	return (table[r]? table[r]->value:NULL);
}

template<typename K,typename V>//线性试探法解决冲突，查找链连续
int HashTable<K, V>::probe4Hit(const K& k){
	int r = HashCode(k) % M;//除余法
	while((table[r]&&k!=table[r]->value)||(!table[r]&&lazyremoval(r))){
		r = (r + 1) % M;
	}
	return r;
}

template<typename K,typename V>
bool HashTable<K, V>::remove(const K& k){
	int r = probe4Hit(k);
	if(!table[r])
		return false;
	else{
		release(table[r]);
		table[r] = NULL;
		markAsRemoved(r);
		N--;
		return true;
	}
}

template<typename K, typename V>
bool HashTable<K, V>::put(K k, V v){
	if(table[probe4Hit(k)])
		return false;
	int r = probe4Free(k);
	table[r] =  new Entry<K, V>(k, v);
	N++;
	if(N*2>M)
		rehash();
	return true;
}

template<typename K, typename V>
int HashTable<K, V>::probe4Free(const K& k){//use linear probe method
	int r = HashCode(k) % M;
	while(table[r])
		r=(r+1)%M;
	return r;
		
}

template<typename K,typename V>
void HashTable<K, V>::rehash(){
	int oldCapacity = M;
	Entry<K, V>** oldTable = table;
	M = primeNLT(2*M, 1048576,"filepath");
	N = 0;
	table  = new Entry<K, V>*[M];
	memset(table, 0, sizeof(Entry<K, V>*)*M);
	release(lazyRemoval);
	lazyRemoval = new BitMap(M);
	for(int i = 0; i<oldCapacity; ++i){
		if(!oldTable[i])
			put(oldTable->key, oldTable->value);
	}
	release(oldTable);
}



