
/*
ʱ��: 2021.09.17
��Ŀ������
����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
*/

#include <string>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		bool arr[256] = { false }; // hash�������ж��ַ����Ƿ����ظ��ַ�

		size_t maxLen = 0;
		size_t len = s.length();
		for (size_t i = 0; i < len; i++) {
			// ��ǰ�����ظ��ַ������ַ������Ȳ��洢��curLen��
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