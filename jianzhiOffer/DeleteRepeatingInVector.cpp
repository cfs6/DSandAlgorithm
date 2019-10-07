#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	vector<string> resv = { "acc","acc","dsa","dst","gas","dsa","gfd"};
	
	vector<string>::iterator it1;
	vector<string>::iterator it2;
	for (it1 = ++resv.begin(); it1 != resv.end();) {
		it2 = find(resv.begin(), it1, *it1);
		cout << *it2 << endl;
		if (it1 != it2)
			it1 = resv.erase(it1);
		else
			it1++;
	}
	for (auto r : resv) {
		cout << r << " ";
	}
	system("pause");
}