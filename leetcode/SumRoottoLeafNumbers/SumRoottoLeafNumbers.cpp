// Source : https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-03
/**********************************************************************************
*
* Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
* An example is the root-to-leaf path 1->2->3 which represents the number 123.
*
* Find the total sum of all root-to-leaf numbers.
*
* For example,
*
*     1
*    / \
*   2   3
*
* The root-to-leaf path 1->2 represents the number 12.
* The root-to-leaf path 1->3 represents the number 13.
*
* Return the sum = 12 + 13 = 25.
*
**********************************************************************************/
#include <iostream>
#include "../common/binary_tree.hpp"

// 由DFS遍历改造而来，分别计算每一个从根节点到叶节点路径上的数字之和
void numOfRootToLeaf(TreeNode *root, vector<int>& vec, int& currentSum)
{
	if (root == NULL)
		return ;

	currentSum *= 10;
	currentSum += root->val;

	bool leaf = (root->left == NULL && root->right == NULL);
	if (leaf)
	{
		vec.push_back(currentSum);
	}
	else
	{
		if (root->left)
			numOfRootToLeaf(root->left, vec, currentSum);
		if (root->right)
			numOfRootToLeaf(root->right, vec, currentSum);
	}

	currentSum -= root->val;
	currentSum /= 10;
}

int sumNumbers(TreeNode *root)
{
	vector<int> vec;    //保存每一条根节点到叶节点路径上的数字集合
	int num = 0;
	numOfRootToLeaf(root, vec, num);

	int sum = 0;
	for (size_t i = 0; i < vec.size(); ++i)
		sum += vec[i];

	return sum;
}

int main()
{
	{
		int a[] = { 1, 2, 3};
		TreeNode* p = createTree(a, sizeof(a) / sizeof(int));

		cout << sumNumbers(p) << "\n";
		cout << "-----------" << "\n";
	}
	{
		int a[] = { 1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 8, 5, 0 };
		TreeNode* p = createTree(a, sizeof(a) / sizeof(int));

		cout << sumNumbers(p) << "\n";
		cout << "-----------" << "\n";
	}
	{
		int a[] = { 5, 4, 8, 11, 0, 13, 4, 7, 2, 0, 0, 5, 1 };
		TreeNode* p = createTree(a, sizeof(a) / sizeof(int));

		cout << sumNumbers(p) << "\n";
		cout << "-----------" << "\n";
	}

	system("pause");
}