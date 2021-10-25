/*
ʱ�䣺2021.10.24
����һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش𰸡�
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	vector<vector<int>> permute(vector<int>& nums) 
	{
		vector<vector<int>> res;
		vector<int> trace;
		backtrace(res, nums, trace, 0, nums.size());
		return res;
	}
private:
	void backtrace(vector<vector<int>> &res, const vector<int>& nums, vector<int> &trace, int first, int len)
	{
		if (len == 0)
		{
			res.push_back(trace);
			return;
		}
		for (int ele : nums)
		{
			vector<int>::iterator inter = find(trace.begin(), trace.end(), ele);
			if (inter != trace.end())
			{
				continue;
			}
			trace.push_back(ele);
			backtrace(res, nums, trace, first + 1, len - 1);
			trace.pop_back();
		}
	}
};