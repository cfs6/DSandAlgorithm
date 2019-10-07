//实现Data类包括month day year成员变量，三种输出格式成员函数
//5-20-2008
//May-20-2008
//2008-May-20
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
class Data {
public:
	Data(int m, int d, int y) {
		month = m;
		day = d;
		year = y;
	}
	~Data() {
			
	}
	void print1(int m, int d, int y) {
		cout << m << "-" << d << "-" << y;
	}

	void print2(int m, int d, int y) {
		string mstr = EnglishTrans(m);
		cout << mstr << "-" << d << "-" << y;
	}

	void print3(int y, int m, int d) {
		string mstr = EnglishTrans(m);
		cout << y << "-" << mstr << "-" << d;
	}

	string EnglishTrans(int m) {
		string mstr;
		switch (m)
		{
		case 1:
			mstr = "January";
			return mstr;
			break;
		case 2:
			mstr = "February";
			return mstr;
			break;
		case 3:
			mstr = "March";
			return mstr;
			break;
		case 4:
			mstr = "April";
			return mstr;
			break;
		case 5:
			mstr = "May";
			return mstr;
			break;
		case 6:
			mstr = "June";
			return mstr;
			break;
		case 7:
			mstr = "July";
			return mstr;
			break;
		case 8:
			mstr = "Auguest";
			return mstr;
			break;
		case 9:
			mstr = "September";
			return mstr;
			break;
		case 10:
			mstr = "October";
			return mstr;
			break;
		case 11:
			mstr = "November";
			return mstr;
			break;
		case 12:
			mstr = "December";
			return mstr;
			break;
		default:
			cout << "Invalid data!" << endl;
			break;
		}
	}

	int month, day, year;
};

int main() {
	cout << "Print type:" << endl;
	cout << endl;
	Data pdata(5, 20, 2019);
	pdata.print1(5,20,2018);
	cout << endl;
	pdata.print2(5,20,2018);
	cout << endl;
	pdata.print3(2018,5,20);
	system("pause");
}