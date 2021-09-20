/*
ʱ��: 2021.09.20
��Ŀ������
������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi] ������ϲ������ص������䣬������һ�����ص����������飬��������ǡ�ø��������е��������䡣
*/

#include <vector>
#include <algorithm>
using namespace std;

// �º������߽�����������
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
			// �жϵ�ǰ�����ڽ�������Ƿ�����ظ�������
			vector<vector<int>>::iterator resIt = res.begin();
			for (; resIt != res.end(); resIt++)
			{
				if (checkOverlap(*it, *resIt))
				{
					break;
				}
			}

			// ����������ص�����ϲ�
			if (resIt != res.end())
			{
				(*resIt)[0] = (*it)[0] < (*resIt)[0] ? (*it)[0] : (*resIt)[0];
				(*resIt)[1] = (*it)[1] < (*resIt)[1] ? (*resIt)[1] : (*it)[1];
			}
			else
			{
				res.push_back(*it); // ����Ӧ�������
			}
		}
		return res;
	}
private:
	// �ж����������Ƿ�����ظ�
	bool checkOverlap(const vector<int> &interval1, const vector<int> &interval2)
	{
		return interval1[1] >= interval2[0] && interval1[0] <= interval2[1];
	}
};