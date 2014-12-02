// Source : https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-01

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

//空间和时间都为O(n)
TreeNode* sortedListToBST(ListNode *head)
{
	if (head == NULL)
		return NULL;

	vector<int> vec;
	ListNode *p = head;
	while (p)
	{
		vec.push_back(p->val);
		p = p->next;
	}

	return sortedListToBST(vec, 0, vec.size() - 1);
}

int main()
{
	{
		int arr[] = { -1, 0, 1, 2 };
		ListNode *root = createList(arr, 4);
		TreeNode *node = sortedListToBST(root);
		cout << "---------\n";
	}
	{
		int arr[] = { 1, 3 };
		ListNode *root = createList(arr, 2);
		TreeNode *node = sortedListToBST(root);
		cout << "---------\n";
	}

	system("pause");
}