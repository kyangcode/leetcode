/*
时间：2021.10.24
题目描述：
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int val) : val(val), next(nullptr) {}
	ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class Solution 
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* head = new ListNode;
		ListNode* p = head;

		ListNode *p1 = l1;
		ListNode *p2 = l2;

		int val = 0;
		int carry = 0;
		while (p1 != nullptr && p2 != nullptr)
		{
			val = p1->val + p2->val + carry;
			carry = 0;
			if (val >= 10)
			{
				val = val - 10;
				carry = 1;
			}

			p1 = p1->next;
			p2 = p2->next;

			p->next = new ListNode(val);
			p = p->next;
		}

		while (p1)
		{
			val = p1->val + carry;
			carry = 0;
			if (val >= 10)
			{
				val = val - 10;
				carry = 1;
			}

			p1 = p1->next;

			p->next = new ListNode(val);
			p = p->next;
		}

		while (p2)
		{
			val = p2->val + carry;
			carry = 0;
			if (val >= 10)
			{
				val = val - 10;
				carry = 1;
			}

			p2 = p2->next;

			p->next = new ListNode(val);
			p = p->next;
		}

		if (carry > 0)
		{
			p->next = new ListNode(carry);
			p = p->next;
		}
		return head->next;
	}
};