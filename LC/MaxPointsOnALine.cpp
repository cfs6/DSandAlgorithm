//max points on a line
//���ڸ�����n��λ��ͬһ��άƽ���ϵĵ㣬��������ж��ٸ���λ��ͬһֱ����
#include<vector>
#include<iostream>
#include<map>
using namespace std;

struct Point {
	int x;
	int y;
};


class Solution {
public:
	/**
	*
	* @param points Point��vector
	* @return int����
	*/
	//����map<float,int>������ͬб�ʵ�һ������Ŀ
	//map��ʵֵ+�뵱ǰ��i�ظ�������������ظ��㼴Ϊ1����Ϊ����ǰб������๲�ߵ���
	//INT_MAX ��ʾб��Ϊ���������
	//������λ����ͬ��ҲΪ���ߵ㣬��repeatCount����ʾλ����ͬ��������Ŀ
	int max(int a, int b)
	{
		return a > b ? a : b;
	}

	int maxPoints(vector<Point>& points) {
		int pointSize = points.size();
		if (pointSize <= 2)
			return pointSize;
		int count = 0;
		for (int i = 0; i < pointSize-1; ++i)
		{
			map<float, int> kmap;
			int repeatCount = 1;
			for (int j = i + 1; j < pointSize; ++j)
			{
				if (points[i].x == points[j].x)
				{
					if (points[i].y == points[j].y)       //������λ����ͬ����¼
					{                                     //�ظ�����
						repeatCount++;
					}
					else                                  //��б��Ϊ�����
					{                                     //��INT_MAX��ʾ
						kmap[INT_MAX]++;
					}
				}
				else
				{
					float k = (points[i].y - points[j].y)*1.0 / (points[i].x - points[j].x);
					kmap[k]++;
				}
			}
			count = max(count, repeatCount);
			for (auto rk : kmap)
			{
				count = max(count, rk.second + repeatCount);
			}
		}
		return count;
	}
	
};

int main()
{
	vector<Point> points;
	Point p1, p2, p3, p4, p5, p6, p7, p8, p9;
	p1.x = 84;
	p1.y = 250;
	p2.x = 0;
	p2.y = 0;
	p3.x = 1;
	p3.y = 0;
	p4.x = 0;
	p4.y = -70;
	p5.x = 0;
	p5.y = -70;
	p6.x = 1;
	p6.y = -1;
	p7.x = 21;
	p7.y = 10;
	p8.x = 42;
	p8.y = 90;
	p9.x = -42;
	p9.y = -230;
	
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);
	points.push_back(p5);
	points.push_back(p6);
	points.push_back(p7);
	points.push_back(p8);
	points.push_back(p9);
	Solution sol;

	int res = sol.maxPoints(points);
	cout << res << endl;
	system("pause");
}