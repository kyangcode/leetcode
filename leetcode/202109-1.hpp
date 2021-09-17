
/*
时间: 2021.09.17
题目描述：
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
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