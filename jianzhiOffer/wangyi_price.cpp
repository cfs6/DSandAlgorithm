//����3����Ҫ��ɵ����������3����������Ҫ�������۵ġ�
//���ȣ�����Բ����κδ��۵����һ������Ȼ��������˵�i������֮��
//����Ի��� | Ai - Aj | �Ĵ�����ɵ�j������ | x | ����x�ľ���ֵ��
//�������������������С���ۡ�
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
