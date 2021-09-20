/*
时间: 2021.09.20
题目描述：
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
*/

#include <vector>
#include <algorithm>
using namespace std;

// 仿函数或者叫做函数对象
class MyCompare
{
public:
	bool operator()(const vector<int> &interval1, const vector<int> &interval2)
	{
		return interval1[0] < interval2[0];
	}
};

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;

		sort(intervals.begin(), intervals.end(), MyCompare());
		for (vector<vector<int>>::iterator it = intervals.begin(); it != intervals.end(); it++)
		{
			// 判断当前区间在结果集中是否存在重复的区间
			vector<vector<int>>::iterator resIt = res.begin();
			for (; resIt != res.end(); resIt++)
			{
				if (checkOverlap(*it, *resIt))
				{
					break;
				}
			}

			// 如果区间有重叠，则合并
			if (resIt != res.end())
			{
				(*resIt)[0] = (*it)[0] < (*resIt)[0] ? (*it)[0] : (*resIt)[0];
				(*resIt)[1] = (*it)[1] < (*resIt)[1] ? (*resIt)[1] : (*it)[1];
			}
			else
			{
				res.push_back(*it); // 这里应该是深拷贝
			}
		}
		return res;
	}
private:
	// 判断两个区间是否存在重复
	bool checkOverlap(const vector<int> &interval1, const vector<int> &interval2)
	{
		return interval1[1] >= interval2[0] && interval1[0] <= interval2[1];
	}
};