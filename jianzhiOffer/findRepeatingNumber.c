//using hashtable (map) to count

#include<map>
#include<vector>
#include<iostream>
using namespace std;
/*
template<typename T>
int* findRepeatingNumber(int* M){
	if(M==NULL)
		return 0;
	map<T,int> n_count;
	vector<int> res_count;
	int M_size = M.size();
	for(int i = 0; i < M_size; i++){
		++n_count[M[i]];
	}
	for(const auto &n:n_count){
		cout<<n.first<<", "<<n.second<<endl; 
		if(n.second>1)
			res_count.push_back(n.first);
	}
//	for(auto &w_c : res_count)
//		cout<<w_c<<" "<<endl;
	
	return res_count;
}
*/
int main(){
	vector<int> M;
	int m;
	while(cin>>m){
		if(m<0)
			break;
		M.push_back(m);
	}
//	if(M==NULL)
//		return 0;
	map<int, int> n_count;
	vector<int> res_count;
	int M_size = M.size();
	for(int i = 0; i < M_size; i++){
		++n_count[M[i]];
	}
	for(const auto &n:n_count){
		cout<<n.first<<", "<<n.second<<endl; 
		if(n.second>1)
			res_count.push_back(n.first);
	}
	cout<<"The result:"<<endl;
	for(auto &res : res_count)
		cout<<res<<" "<<endl;
//	int res = findRepeatingNumber(M);
//	cout<<"the result:"<<endl;
	
	return 0;
}