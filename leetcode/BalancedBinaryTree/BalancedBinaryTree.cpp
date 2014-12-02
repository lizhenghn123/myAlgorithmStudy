// Source : https://oj.leetcode.com/problems/validate-binary-search-tree/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-02
/**********************************************************************************
*
* Given a binary tree, determine if it is height-balanced.
*
* For this problem, a height-balanced binary tree is defined as a binary tree in which
* the depth of the two subtrees of every node never differ by more than 1.
*
**********************************************************************************/
#include <iostream>
#include "../common/binary_tree.hpp"
using namespace std;

int treeDepth(TreeNode *root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;

	int leftDepth = treeDepth(root->left);
	int rightDepth = treeDepth(root->right);

	return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

bool isBalanced(TreeNode *root)
{
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return true;

	int leftDepth = treeDepth(root->left);
	int rightDepth = treeDepth(root->right);

	if (leftDepth - rightDepth > 1 || leftDepth - rightDepth < -1)
		return false;

	return isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
	TreeNode *root = new TreeNode(10);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(1);
	TreeNode *node3 = new TreeNode(20);

	root->left = node1;
	node1->left = node2;
	node1->right = node3;

	cout << isBalanced(root) << "\n";

	system("pause");
}