/*
ʱ��: 2021.11.29
��Ŀ������
���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
*/


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode *newHead = reverseList(head->next);

		ListNode *tail = newHead;
		while (tail->next != nullptr) tail = tail->next;
		tail->next = head;
		tail->next->next = nullptr;
		return newHead;
	}
};