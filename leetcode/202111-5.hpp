/*
时间: 2021.11.29
题目描述：
编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。
*/

#include <cstdint>
using namespace std;
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n > 0) {
			if (n % 2 == 1) {
				count++;
			}
			n /= 2;
		}
		return count;
	}
};