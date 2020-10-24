/*给出一组区间，请合并所有重叠的区间。
例如，
给出[10,30],[20,60],[80,100],[150,180],
返回[10,60],[80,100],[150,180].*/
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool compare(Interval i1, Interval i2)
{
	return i1.start < i2.start;
}

class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {

		if (intervals.size() == 0)
			return intervals;
		sort(intervals.begin(), intervals.end(), compare);
		int i = 0;
		while (i < intervals.size() - 1)
		{
			if (intervals[i].end >= intervals[i + 1].start)
			{
				if (intervals[i + 1].end >= intervals[i].end)
					intervals[i].end = intervals[i + 1].end;

				auto it = intervals.begin();
				int k = 0;
				while (k != i + 1)
				{
					it++;
					++k;
				}

				intervals.erase(it);
			}
			else
			{
				++i;
			}
		}
		return intervals;
	}
};