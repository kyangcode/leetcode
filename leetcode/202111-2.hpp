/*
ʱ��: 2021.11.29
��Ŀ������
����һ���������� nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�

��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�
*/
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (size == 0) {
			return 0;
		}
		int fast = 1;
		int slow = 1;
		while (fast < size) {
			if (nums[fast] != nums[fast - 1]) {
				nums[slow++] = nums[fast];
			}
			fast++;
		}
		return slow;
	}
};