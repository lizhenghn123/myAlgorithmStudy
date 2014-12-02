// Source : https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-01

/**********************************************************************************
*
* Given a binary tree, flatten it to a linked list in-place.
*
* For example,
* Given
*
*          1
*         / \
*        2   5
*       / \   \
*      3   4   6
*
* The flattened tree should look like:
*
*    1
*     \
*      2
*       \
*        3
*         \
*          4
*           \
*            5
*             \
*              6
*
*
* Hints:
* If you notice carefully in the flattened tree, each node's right child points to
* the next node of a pre-order traversal.
*
**********************************************************************************/
#include <iostream>
#include "../common/binary_tree.hpp"

void preorderTraversalNodes(TreeNode *root, vector<TreeNode*>& orders)
{
	if (root == NULL)
		return;

	orders.push_back(root);

	if (root->left)
		preorderTraversalNodes(root->left, orders);
	if (root->right)
		preorderTraversalNodes(root->right, orders);
}

vector<TreeNode*> preorderTraversalNodes(TreeNode *root)
{
	vector<TreeNode*> orders;
	preorderTraversalNodes(root, orders);
	return orders;
}

// 先序遍历所有节点，然后将每个节点的左子树置NULL，并修改其右子树指向
void flatten(TreeNode *root) 
{
	if (root == NULL/* || root->left == NULL || root->right == NULL*/) //这都不行
		return;

	vector<TreeNode*> orders;
	preorderTraversalNodes(root, orders);

	const size_t len = orders.size();
	for (size_t i = 0; i < len; ++i)
	{
		orders[i]->left = NULL;
		if (i == len - 1) // last one
		{
			orders[i]->right = NULL;
		}
		else
		{
			orders[i]->right = orders[i + 1];
		}
	}
}

int main()
{
	{
		int a[] = { 1, 2 };
		TreeNode *p = createTree(a, 2);
		flatten(p);
		cout << "-------------\n";
	}
	{
		int a[] = { 1, 0, 2, 3 };
		TreeNode *p = createTree(a, 4);
		flatten(p);
		cout << "-------------\n";
	}
	system("pause");
}