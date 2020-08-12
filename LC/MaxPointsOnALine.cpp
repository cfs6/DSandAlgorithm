//max points on a line
//对于给定的n个位于同一二维平面上的点，求最多能有多少个点位于同一直线上
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
	* @param points Point类vector
	* @return int整型
	*/
	//采用map<float,int>计量相同斜率的一组点的数目
	//map的实值+与当前点i重复点个数（若无重复点即为1）即为所求当前斜率下最多共线点数
	//INT_MAX 表示斜率为无穷大的情况
	//若两点位置相同，也为共线点，以repeatCount量表示位置相同点的组的数目
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
					if (points[i].y == points[j].y)       //若两点位置相同，记录
					{                                     //重复点数
						repeatCount++;
					}
					else                                  //若斜率为无穷大，
					{                                     //以INT_MAX表示
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