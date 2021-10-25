/*
时间：2021.10.25
题目描述：
实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

说明：

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。
*/
#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
		{
			return 0;
		}

		int needleLen = needle.length();
		int haystackLen = haystack.length();
		for (int i = 0; i <= haystackLen - needleLen; i++)
		{
			int j = 0;
			for (; j < needleLen; j++)
			{
				if (needle[j] != haystack[i + j])
				{
					break;
				}
			}
			if (j == needleLen)
			{
				return i;
			}
		}
		return -1;
	}
};

