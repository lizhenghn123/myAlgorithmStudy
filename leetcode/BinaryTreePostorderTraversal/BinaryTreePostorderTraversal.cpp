// Source : https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-30

/**********************************************************************************
*
* Given a binary tree, return the postorder traversal of its nodes' values.
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
* return [3,2,1].
*
* Note: Recursive solution is trivial, could you do it iteratively?
*
**********************************************************************************/
#include <iostream>
#include <vector>
#include "../common/binary_tree.hpp"
using namespace std;

void inorderTraversal(TreeNode *root, vector<int>& orders)
{
	if (root == NULL)
		return;

	if (root->left)
		inorderTraversal(root->left, orders);

	orders.push_back(root->val);

	if (root->right)
		inorderTraversal(root->right, orders);
}

vector<int> inorderTraversal(TreeNode *root)
{
	vector<int> orders;
	inorderTraversal(root, orders);
	return orders;
}

int main()
{
	system("pause");
}