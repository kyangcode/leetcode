/*
时间: 2021.09.19
题目描述：
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？
*/
#include <vector>
using namespace std;

// 链表节点
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
		// 存储所有结点的地址到vector
		vector<ListNode*> v;
		v.reserve(30);

		ListNode *p = head;
		while (p) {
			v.push_back(p);
			p = p->next;
		}

		size_t size = v.size();
		if (n == size) // 删除头结点
		{
			head = v[0]->next;
			delete v[0];
		}
		else if (n == 1) // 删除尾结点
		{
			v[size - 2]->next = nullptr;
			delete v[size - 1];
		}
		else  // 删除中间结点
		{
			size_t index = size - n;
			v[index - 1]->next = v[index]->next;
			delete v[index];
		}
		return head;
	}
};