// Source : https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-02

/**********************************************************************************
*
* Given a singly linked list where elements are sorted in ascending order,
* convert it to a height balanced BST.
*
**********************************************************************************/
#include <iostream>
#include "../common/single_list.hpp"
#include "../common/binary_tree.hpp"
using namespace std;

TreeNode* sortedListToBST(const std::vector<int>& vec, int start, int end)
{
	if (start > end || vec.empty())
		return NULL;

	int mid = start + (end - start) / 2;

	TreeNode *node = new TreeNode(vec[mid]);
	node->left = sortedListToBST(vec, start, mid - 1);
	node->right = sortedListToBST(vec, mid + 1, end);

	return node;
}

TreeNode *sortedArrayToBST(vector<int> &num)
{
	return sortedListToBST(num, 0, num.size() - 1);
}

int main()
{
	{
		vector<int> v = {};
		TreeNode *root = sortedArrayToBST(v);
	}
	{
		vector<int> v = { 1 };
		TreeNode *root = sortedArrayToBST(v);
	}
	{
		vector<int> v = { 1, 3 };
		TreeNode *root = sortedArrayToBST(v);
	}
	{
		vector<int> v = { -1, 0, 1, 2 };
		TreeNode *root = sortedArrayToBST(v);
	}

	system("pause");
}