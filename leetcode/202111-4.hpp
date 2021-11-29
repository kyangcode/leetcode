/*
时间: 2021.11.29
题目描述：
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
*/
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) {
			return res;
		}
		res.push_back(root->val);

		vector<int> vec = preorderTraversal(root->left);
		for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
			res.push_back(*iter);
		}

		vec = preorderTraversal(root->right);
		for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
			res.push_back(*iter);
		}
		return res;
	}
};