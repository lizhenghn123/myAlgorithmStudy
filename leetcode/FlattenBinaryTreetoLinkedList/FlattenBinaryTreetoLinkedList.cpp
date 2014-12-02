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
TreeNode* createTree(int a[], int n)
{
	if (n <= 0) return NULL;

	TreeNode **tree = new TreeNode*[n];

	for (int i = 0; i<n; i++) {
		if (a[i] == 0){
			tree[i] = NULL;
			continue;
		}
		tree[i] = new TreeNode(a[i]);
	}
	int pos = 1;
	for (int i = 0; i<n && pos<n; i++) {
		if (tree[i]){
			tree[i]->left = tree[pos++];
			if (pos<n){
				tree[i]->right = tree[pos++];
			}
		}
	}
	return tree[0];
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