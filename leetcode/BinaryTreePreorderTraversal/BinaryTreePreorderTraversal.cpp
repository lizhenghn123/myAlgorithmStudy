// Source : https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-30

/**********************************************************************************
*
* Given a binary tree, return the preorder traversal of its nodes' values.
*
* For example:
* Given binary tree {1,#,2,3},
*
*    1
*     \
*      2
*     /
*    3
*
* return [1,2,3].
*
* Note: Recursive solution is trivial, could you do it iteratively?
*
**********************************************************************************/
#include <iostream>
#include <vector>
#include "../common/binary_tree.hpp"
using namespace std;


void preorderTraversal(TreeNode *root, vector<int>& orders)
{
	if (root == NULL)
		return;

	orders.push_back(root->val);

	if (root->left)
		preorderTraversal(root->left, orders);
	if (root->right)
		preorderTraversal(root->right, orders);
}

vector<int> preorderTraversal(TreeNode *root)
{
	vector<int> orders;
	preorderTraversal(root, orders);
	return orders;
}

int main()
{
	system("pause");
}