/*
ʱ��: 2021.09.20
��Ŀ������
����һ���������������������ڵĽڵ㣬�����ؽ����������

�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
*/
#include <vector>
#include <iostream>
#include <algorithm>
// ������
struct ListNode {
	int val;
	ListNode *next;

	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ����һ������
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
					// ������������λ��
					head = cur->next;
					cur->next = cur->next->next;
					head->next = cur;
		
					// ָ��ǰ��
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
					// ������������λ��
					prev->next = cur->next;
					cur->next = cur->next->next;
					prev->next->next = cur;

					// ָ��ǰ��
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