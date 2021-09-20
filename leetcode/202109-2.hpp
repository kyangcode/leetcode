/*
ʱ��: 2021.09.19
��Ŀ������
����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣

���ף����ܳ���ʹ��һ��ɨ��ʵ����
*/
#include <vector>
using namespace std;

// ����ڵ�
struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) :val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		// �洢���н��ĵ�ַ��vector
		vector<ListNode*> v;
		v.reserve(30);

		ListNode *p = head;
		while (p) {
			v.push_back(p);
			p = p->next;
		}

		size_t size = v.size();
		if (n == size) // ɾ��ͷ���
		{
			head = v[0]->next;
			delete v[0];
		}
		else if (n == 1) // ɾ��β���
		{
			v[size - 2]->next = nullptr;
			delete v[size - 1];
		}
		else  // ɾ���м���
		{
			size_t index = size - n;
			v[index - 1]->next = v[index]->next;
			delete v[index];
		}
		return head;
	}
};