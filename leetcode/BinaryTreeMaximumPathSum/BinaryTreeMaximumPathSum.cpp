// Source : https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-03
/**********************************************************************************
*
* Given a binary tree, find the maximum path sum.
*
* The path may start and end at any node in the tree.
*
* For example:
* Given the below binary tree,
*
*        1
*       / \
*      2   3
*
* Return 6.
*
**********************************************************************************/
#include <iostream>
#include "../common/binary_tree.hpp"
using namespace std;

//ERROR!!!!!
void maxPathSum(TreeNode *root, int& totalSum, int& currMaxSum)
{
	if (root == NULL)
		return;

	//if (totalSum > 0)
	//	totalSum += root->val;
	//else
	//	totalSum = root->val;
	if (root->val > 0)
	{
		totalSum += root->val;
		if (totalSum > currMaxSum)
			currMaxSum = totalSum;
	}
	else if (root->val > currMaxSum)
	{
		currMaxSum = root->val;
	}

	if (root->left)
		maxPathSum(root->left, totalSum, currMaxSum);
	if (root->right)
		maxPathSum(root->right, totalSum, currMaxSum);

	//totalSum -= root->val;
}

int maxPathSum(TreeNode *root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return root->val;

	int totalSum = 0, currMaxSum = root->val;
	maxPathSum(root, totalSum, currMaxSum);
	return currMaxSum;
}

int main()
{
	{
		int a[] = { 1, 2, 3 };
		TreeNode *p = createTree(a, sizeof(a) / sizeof(a[0]));
		cout << maxPathSum(p) << "\n";
	}
	{
		int a[] = { -3 };
		TreeNode *p = createTree(a, sizeof(a) / sizeof(a[0]));
		cout << maxPathSum(p) << "\n";
	}
	{
		int a[] = { 1, -2, 3 };
		TreeNode *p = createTree(a, sizeof(a) / sizeof(a[0]));
		cout << maxPathSum(p) << "\n";
	}
	{
		int a[] = { -2, -1 };
		TreeNode *p = createTree(a, sizeof(a) / sizeof(a[0]));
		cout << maxPathSum(p) << "\n";
	}
	{
		int a[] = { 1, -2, -3, 1, 3, -2, 0, -1 };
		TreeNode *p = createTree(a, sizeof(a) / sizeof(a[0]));
		cout << maxPathSum(p) << "\n";   // 5, but should cout 3!!!!
	}
	system("pause");
}