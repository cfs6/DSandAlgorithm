#include<Vector.h>
#include<PQ.h>
#define Parent(i) ((i-1)>>1)
#define LChild(i) (1+(i<<1))
#define RChild(i) ((i+1)<<1)
#define max(i,j) elem[i]>elem[j]?i:j

template<typename T>
class PQ_ComplHeap:public PQ<T>, public Vector<T>{
protected:
	Rank percolateDown(Rank n, Rank i);//n:the size of the heap;  i:the current entry of the heap
	Rank percolateUp(Rank i);
	void heapify(Rank n);
public:
    PQ_ComplHeap();
	PQ_ComplHeap(T* A,Rank n){
		copyFrom(A, 0, n);
		heapify(n);
	}
	void insert(T);
	T getMax();
	T DelMax();
	bool inHeap(Rank n, Rank i);
};

template<typename T>
inline bool PQ_ComplHeap<T>::inHeap(Rank n, Rank i){
	return ((i>=0)&&(i<n));
}

template<typename T>
T PQ_ComplHeap<T>::getMax(){
	T x = elem[0];
	return x;
}

template<typename T>
void PQ_ComplHeap<T>::insert(T e){
	Vector<T>::insert(e);
	percolateUP(size-1);
}

template<typename T>
Rank PQ_ComplHeap<T>::percolateUp(Rank i){
	while(Parent(i)){
		Rank j = Parent(i);
		if(elem[j]>elem[i])
			break;
		swap(elem[i],elem[j]);
		i = j;
	}
	return i;
}

template<typename T>
T PQ_ComplHeap<T>::delMax(){
	T maxElem = getMax();
	elem[0] = elem[size-1];
	Vector<T>::remove(size-1);
	size--;
	percolateDown(size, 0);
}
template<typename T>
Rank PQ_ComplHeap<T>::percolateDown(Rank n, Rank i){
	Rank j;
	while(i !=( j = (inHeap(n, lChild(i))?max(i,lchild(i)):(inHeap(n, rChild(i))?max(i,rChild(i)):i)))){
		swap(elem[i], elem[j]);
		i = j;
	}
	return i;
}

template<typename T>
void PQ_ComplHeap<T>::heapify(Rank n){  //floyd heapify
	int i = Parent(n-1);
	for(i; i>=0; i--)
		percolateDown(n, i);
}

template<typename T>
void Vector<T>::heapSort(vector<T> elem){
	int n = elem.size();
	Vector<T> sortedElem;
	PQ_ComplHeap<T> H = new PQ_ComplHeap(elem, n);
	while(!H.emnpty())
		sortedElem = H.delMax();
}
