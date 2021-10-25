/*
ʱ�䣺2021.10.25
��Ŀ������
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��
*/

#include <vector>
using namespace std;

class Solution 
{
public:
	int searchInsert(vector<int>& nums, int target) 
	{
		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (target > nums[mid])
			{
				left = mid + 1;
			}
			else if (target < nums[mid])
			{
				right = mid - 1;
			}
			else
			{
				return mid;
			}
		}

		if (target > nums[mid])
		{
			return mid + 1;
		}
		else
		{
			return mid;
		}
	}
};