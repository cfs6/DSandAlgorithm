//cout控制小数点后精度
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	float a = 100;
	float b = 3;
	float c = a / b;
	cout.precision(4);
	cout << setiosflags(ios::fixed) << setprecision(3) << c << endl;
	system("pause");

}