//Get the digit of the sequence
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int digitofsqeuence(int n) {
	int count = 0;
	int digit = 1;
	int i;
	for (i = 0; count < n; ++i) {
		int num = i;
		int numcount = 0;
		while (num != 0) {
			num /= 10;
			numcount++;
		}
		count += numcount;
	}
	int back_ = count - n;
	int k = pow(10, back_ + 1);
	int res = i%k / (pow(10, back_));
	return res;
}

//Another way

int digitofsequence2(int n) {
	int d = 1;
	int num,res;
	while (digitofnum(d) < n) {
		++d;
	}
	int rcount = n - digitofnum(--d);
//	++d;
	int quo = rcount / d;
	int rem = rcount % d;
	
	if (rem > 0) {
		num = pow(10, d - 1) + quo + 1;
		res = getdigitofnum(num, rem);
	}
	else {
		num = pow(10, d - 1) + quo;
		res = num % 10;
	}
	return res;
}

int digitofnum(int d) {
	if (d <= 0)
		return 0;
	int i = 1;
	int count = 0;
	int numcount = 0;
	do{
		numcount = numofsection(i);
		count += i*numcount;
		++i;
	}while (i <= d);
	return count;
}

int numofsection(int n) {
	int count = 9 * pow(10, n - 1);
	return count;
}

int getdigitofnum(int num, int digit) {
	int count = 0;
	int num_ = num;
	int res;
	while (num_ != 0) {
		num_ /= 10;
		++count;
	}
	int rcount = count - digit + 1;
	res = num % (int)(pow(10, rcount));
	res = res / (pow(10, rcount - 1));
	return res;
}