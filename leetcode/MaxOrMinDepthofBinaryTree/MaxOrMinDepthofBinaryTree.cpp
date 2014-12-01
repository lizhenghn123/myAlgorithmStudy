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
//注意下面不要直接写成 std::min(minDepth(root->left) + 1, minDepth(root->right) + 1);
//对于[1, 2]的二叉树来说，其高度是2，上面的实现会输出1，因为1的右子树不存在，不应该求其深度。
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