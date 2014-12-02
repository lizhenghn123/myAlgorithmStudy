// Source : https://oj.leetcode.com/problems/validate-binary-search-tree/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-02
/**********************************************************************************
*
* Given a binary tree, determine if it is a valid binary search tree (BST).
*
* Assume a BST is defined as follows:
*
* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.
*
**********************************************************************************/
#include <iostream>
#include "../common/single_list.hpp"
#include "../common/binary_tree.hpp"
using namespace std;


//bool isValidBST2(TreeNode *root)                    //error!!!   10 2 # 1 20  
//{
//	if (root == NULL)
//		return true;
//	
//	if (root->left && root->left->val >= root->val)
//		return false;
//	if (root->right && root->right->val <= root->val)
//		return false;
//
//	return isValidBST2(root->left) && isValidBST2(root->right);
//}

void inorderTraversal(TreeNode *root, vector<int>& orders)
{
	if (root == NULL)
		return;

	if (root->left)
		inorderTraversal(root->left, orders);

	orders.push_back(root->val);

	if (root->right)
		inorderTraversal(root->right, orders);
}

bool isValidBST(TreeNode *root)
{
	if (root == NULL)
		return true;

	vector<int> inOrders;
	inorderTraversal(root, inOrders);  // 对BST进行中序遍历的序列必须是有序的

	for (size_t i = 0; i < inOrders.size() - 1; ++i)
	{
		if (inOrders[i] >= inOrders[i + 1])
			return false;
	}

	return true;
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

	cout << isValidBST(root) << "\n";

	system("pause");
}