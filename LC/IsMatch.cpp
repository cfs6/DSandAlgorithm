//ͨ���ƥ��
/*
��ʵ��֧��'?'and'*'.��ͨ���ģʽƥ��
'?' ����ƥ���κε����ַ���
'*' ����ƥ���κ��ַ����У����������У���
���������ַ����Ƿ�ƥ��
*/
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
class Solution {
public:
	/*�ؼ��� '*' �����ﶨ���� i �� j �Ļ��ݵ�:ÿ������ '*' ʱ��
	��¼ i �Ļ��ݵ� i_recall = i;��¼ j �Ļ��ݵ� j_recall = ++j��
	����ѡ�� j �������λ�ã���Ϊ��ʱ j Ϊ '*'�������ú����ģʽ
	��ƥ���Ԫ�ء� 
	����������ƥ��ĵ�ʱ���ͻ���뵽�� 3 �� if��
	��ʱ�� i ���ݵ� i_recall ��ͬʱ i_recall ������j ���ݵ� j_recall��
	��ʾ��ԭ����¼�Ļ��ݵ��� '*' ��ƥ�䣬����������һ�ֵ�ƥ�䡣 
	���Ҫ��ĩβ�� '*' �����ԣ��� p[j] Ϊ�������ƥ����ɣ�
	������ʣ��Ԫ��˵����ƥ�䡣*/
	bool isMatch(string s, string p)
	{
		int i = 0, j = 0;
		int j_recall = 0, i_recall = 0;
		while (s[i])
		{
			if (p[j] == '?' || s[i]==p[j])
			{
				++i;
				++j;
				continue;
			}
			if (p[j] == '*')
			{
				i_recall = i;
				j_recall = ++j;
				continue;
			}
			if (j_recall)
			{
				i = ++i_recall;
				j = j_recall;
				continue;
			}
			return false;	
		}
		while (p[j] == '*')
			++j;
		return !p[j];
	}
};