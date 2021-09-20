/*
时间: 2021.09.20
题目描述：
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/
#include <vector>
#include <iostream>
#include <algorithm>
// 链表结点
struct ListNode {
	int val;
	ListNode *next;

	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 创建一个链表
ListNode* createList(const std::vector<int> &v)
{
	ListNode *head = nullptr;
	ListNode *tail = nullptr;
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		ListNode *p = new ListNode(*it);
		if (tail == nullptr)
		{
			head = p;
			tail = p;
		}
		else
		{
			tail->next = p;
			tail = tail->next;
		}
	}
	return head;
}

void printList(const ListNode *head)
{
	const ListNode *p = head;
	while (p)
	{
		std::cout << p->val << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *cur = head;
		ListNode *prev = nullptr;
		
		while (cur != nullptr) 
		{
			if (cur == head)
			{
				if (cur->next != nullptr)
				{
					// 交换两个结点的位置
					head = cur->next;
					cur->next = cur->next->next;
					head->next = cur;
		
					// 指针前移
					prev = cur;
					cur = cur->next;
					
				}
				else
				{
					break;
				}
			}
			else
			{
				if (cur->next != nullptr)
				{
					// 交换两个结点的位置
					prev->next = cur->next;
					cur->next = cur->next->next;
					prev->next->next = cur;

					// 指针前移
					prev = cur;
					cur = cur->next;
				}
				else
				{
					break;
				}
			}
		}

		return head;
	}
};