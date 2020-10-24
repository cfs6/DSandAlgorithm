//1007 Maximum Subsequence Sum
//ע��ȫΪ������ֻ�и�����0�����
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int k, a;
	vector<int> pArray;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> a;
		pArray.push_back(a);
	}

	int start,end;
	for (start = 0; start < pArray.size(); ++start) {
		if (pArray[start] >= 0)                              //">0"  ����ʾ��[-1,-2-3,-4] ��[-1,0,0,-2]�Ĳ�ͬ
			break;
	}
	if (start == pArray.size()) {                                      //ȷ����ʼ���Լ��ж��Ƿ�ȫΪ����
		cout << "0" << " " << pArray[0] << " " << pArray[pArray.size() - 1];
		return 0;
	}
	for (end = pArray.size()-1; end > 0; --end) {
		if (pArray[end] >= 0)
			break;
	}

	int maxSum = pArray[start];
	int seqSum;
	int rstart=start, rend=start;
	for (int s = start; s < end; ++s) {
		int max = pArray[s];
		
		for (int e = s+1; e <= end; ++e) {
			max += pArray[e];
			if (maxSum < max) {
				maxSum = max;
				rstart = s;
				rend = e;
			}
		}
	}
	

	cout << maxSum << " " << pArray[rstart] << " " << pArray[rend];
	system("pause");

}



//�ö�ά����д��: k�ܴ�ʱ���ڴ泬��


#include<iostream>
#include<vector>
using namespace std;

int main() {
	int k, a;
	vector<int> pArray;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> a;
		pArray.push_back(a);
	}
	
	int start, end;
	for (start = 0; start < pArray.size(); ++start) {
		if (pArray[start] >= 0)
			break;
	}
	if (start == pArray.size()) {
		cout << "0" << " " << pArray[0] << " " << pArray[pArray.size() - 1];
		return 0;
	}
	for (end = pArray.size() - 1; end > 0; --end) {
		if (pArray[end] >= 0)
			break;
	}
	vector<vector<int>> sum(k, vector<int>(k));
	for (int i = 0; i < k; ++i) {
		for (int j = i; j < k; ++j) {
			sum[i][j] = 0;
		}

	}

	for (int s = start; s <= end; ++s) {
		for (int e = s; e <= end; ++e) {
			if (s == e)
				sum[s][e] = pArray[s];
			else {
				sum[s][e] = sum[s][e - 1] + pArray[e];
			}
		}
	}

	int maxSum = pArray[start];
	int resStart = start, resEnd = start;
	for (int i = start; i <= end; ++i) {
		for (int j = i; j <= end; ++j) {
			if (maxSum < sum[i][j]) {
				maxSum = sum[i][j];
				resStart = i;
				resEnd = j;
			}
		}
	}

	cout << maxSum << " " << pArray[resStart] << " " << pArray[resEnd];
	system("pause");

}