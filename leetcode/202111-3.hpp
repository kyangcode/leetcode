/*
时间: 2021.11.29
题目描述：
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		size_t size = strs.size();
		if (size == 0) {
			return "";
		}

		size_t idx = 1;
		string prefix = strs[0];
		while (idx < strs.size()) {
			prefix = longestCommonPrefix(prefix, strs[idx]);
			idx++;
		}
		return prefix;
	}

	string longestCommonPrefix(const string &s1, const string &s2) {
		size_t s1Len = s1.length();
		size_t s2Len = s2.length();
		if (s1Len == 0 || s2Len == 0) {
			return ""; 
		}

		size_t idx = 0;
		while (idx < s1Len && idx < s2Len && s1[idx] == s2[idx]) idx++;
		return s1.substr(0, idx);
	}
};