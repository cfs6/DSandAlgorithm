//你有3个需要完成的任务，完成这3个任务是需要付出代价的。
//首先，你可以不花任何代价的完成一个任务；然后，在完成了第i个任务之后，
//你可以花费 | Ai - Aj | 的代价完成第j个任务。 | x | 代表x的绝对值。
//计算出完成所有任务的最小代价。
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	long long pfirst = a>b ? (a>c ? a : c) : (b>c ? b : c);
	long long psecond = a>b ? (b>c ? b : c) : (a>c ? a : c);
	long long pthird = a>b ? (b>c ? c : b) : (a>c ? c : a);
	int res = pfirst - psecond + psecond - pthird;
	cout << res;
	system("pause");
}
