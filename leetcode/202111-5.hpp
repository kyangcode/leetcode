/*
ʱ��: 2021.11.29
��Ŀ������
��дһ��������������һ���޷����������Զ����ƴ�����ʽ��������������Ʊ��ʽ������λ��Ϊ '1' �ĸ�����Ҳ����Ϊ������������
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