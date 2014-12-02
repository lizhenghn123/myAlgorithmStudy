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