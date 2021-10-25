/*
时间：2021.10.25
题目描述：
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
*/
#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode* rotateRight(ListNode* head, int k)
	{
		if (head == nullptr)
		{
			return nullptr;
		}
		if (k == 0)
		{
			return head;
		}

		ListNode *tail = head;
		while (tail->next) tail = tail->next;

		size_t len = 0;
		ListNode *p = head;
		while (p)
		{
			len++;
			p = p->next;
		}
		k = (k - 1) % len + 1;

		int count = len - k;
		ListNode* newHead = head;
		ListNode* prev = nullptr;
		while (count--)
		{
			prev = newHead;
			newHead = newHead->next;
		}
		if (prev != nullptr)
		{
			prev->next = nullptr;
			tail->next = head;
		}
		return newHead;
	}
};