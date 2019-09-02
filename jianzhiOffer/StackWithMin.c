//Stack with min
#include<stack>
template<typename T>
class StackWithMin{
public:
	void push(const T& v);
	void pop();
	T min();
private:
	Stack<T> dataStack;
	Stack<T> minStack;
}
template<class T>
void StackWithMin<T>::push(const T& v){
	if(!dataStack.full())
		dataStack.push(v);
	if(minStack.empty)
		minStack.push(v);
	else{
		if(v<minStack.top())
			minStack.push(v);
		else
			minStack.push(minStack.top());
	}
}

template<typename T>
void StackWithMin<T>::pop(){
	if(dataStack.empty()||minStack.empty())
		return;
	eles{
		dataStack.pop();
		minStack.pop();
	}
}

template<typename T>
T StackWithMin<T>::min(){
	if(minStack.empty()||dataStack.empty())
		return;
	T minV = minStack.top();
	return minV;
}
