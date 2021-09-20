
/*
时间: 2021.09.17
题目描述：
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/

#include <string>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		bool arr[256] = { false }; // hash表，用来判断字符串是否有重复字符

		size_t maxLen = 0;
		size_t len = s.length();
		for (size_t i = 0; i < len; i++) {
			// 求当前不含重复字符最大的字符串长度并存储在curLen中
			size_t curLen = 0;
			memset(arr, 0, sizeof(arr));
			for (size_t j = i; j < len; j++) {
				char ch = s[j];
				if (arr[ch]) {
					break;
				}
				arr[ch] = true;
				curLen++;
			}

			if (curLen > maxLen) {
				maxLen = curLen;
			}
		}
		return maxLen;
	}
};