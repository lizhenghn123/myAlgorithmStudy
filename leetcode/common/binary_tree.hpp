#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include <vector>
#include <queue>
#include <stack>
using namespace std;

//Definition for binary tree
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//TODO 关于二叉树的都要写非递归遍历的算法


//层次遍历
vector<int> levelorderTraversal(TreeNode *root)
{
	vector<int> orders;

	queue<TreeNode*> queue;
	queue.push(root);
	while (!queue.empty())
	{
		TreeNode *node = queue.front();
		queue.pop();

		orders.push_back(node->val);

		if (node->left)
			queue.push(node->left);
		if (node->right)
			queue.push(node->right);
	}

	return orders;
}

#endif  /* BINARY_TREE_HPP */
