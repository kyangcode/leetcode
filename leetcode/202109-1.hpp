
/*
ʱ��: 2021.09.17
��Ŀ������
����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
*/

#include <string>
#include <set>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		size_t maxLen = 0;
		for (size_t i = 0; i < s.length(); i++) {
			set<char> tmp;
			size_t curLen = 0;
			for (size_t j = i; j < s.length(); j++) {
				pair<set<char>::iterator, bool> p = tmp.insert(s[j]);
				if (!p.second) {
					break;
				}
				curLen++;
			}
			if (curLen > maxLen) {
				maxLen = curLen;
			}
		}
		return maxLen;
	}
};