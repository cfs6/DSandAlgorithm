//build a stack by 2 queue
#include<queue>
using namespace std;
template<typename T>
class CStack{
public:
	CStack();
	~CStack();
	void push(const T& node);
	T pop();
private:
	quque<T> queue1;
	queue<T> queue2;
};

template<typename T>
void CStack::push(const T& node){
	queue1.push(node);
}

template<typename T>
T CStack::pop(){
	if(!stack1.empty()&&stack2.empty()){
		int size1 = queue1.size();
		for(int i = 0; i<size1-1; i++){
			T fr1 = queue1.front();
			queue1.pop();
			queue2.push(fr1);
		}
		T node = queue1.front();
		queue1.pop();
	}
	else if(!stack2.empty()&&stack1.empty()){
		int size2 = queue2.size();
		for(int j = 0; j<size2-j; j++){
			T frj = queue2.front();
			queue2.pop();
			queue1.push(fr1);
		}
		T node = queue2.front();
		queue2.pop();
	}
	else
		return 0;
	return node;
}
