// Source : https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
// Source : https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-01
#include <iostream>
#include "../common/binary_tree.hpp"

/**********************************************************************************
*
* Given a binary tree, find its minimum depth.
*
* The minimum depth is the number of nodes along the shortest path from the root node
* down to the nearest leaf node.
*
**********************************************************************************/
//ע�����治Ҫֱ��д�� std::min(minDepth(root->left) + 1, minDepth(root->right) + 1);
//����[1, 2]�Ķ�������˵����߶���2�������ʵ�ֻ����1����Ϊ1�������������ڣ���Ӧ��������ȡ�
int minDepth(TreeNode *root) 
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;

	int left = root->left ? minDepth(root->left) + 1 : INT_MAX;
	int right = root->right ? minDepth(root->right) + 1 : INT_MAX;

	return left < right ? left : right;
}

/**********************************************************************************
*
* Given a binary tree, find its maximum depth.
*
* The maximum depth is the number of nodes along the longest path from the root node
* down to the farthest leaf node.
*
**********************************************************************************/
int maxDepth(TreeNode *root) 
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;

	int left = root->left ? maxDepth(root->left) + 1 : 0;
	int right = root->right ? maxDepth(root->right) + 1 : 0;

	return left > right ? left : right;
}

int main()
{
	system("pause");
}