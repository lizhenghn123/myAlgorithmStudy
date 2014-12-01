// Author : lizhenghn@gmail.com
// Date   : 2014-12-01

#include <iostream>
#include <vector>
#include <queue>
#include "../common/binary_tree.hpp"

// Source : https://oj.leetcode.com/problems/symmetric-tree/
/**********************************************************************************
*
* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
*
* For example, this binary tree is symmetric:
*
*     1
*    / \
*   2   2
*  / \ / \
* 3  4 4  3
*
* But the following is not:
*
*     1
*    / \
*   2   2
*    \   \
*    3    3
*
* Note:
* Bonus points if you could solve it both recursively and iteratively.
*
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*
* OJ's Binary Tree Serialization:
*
* The serialization of a binary tree follows a level order traversal, where '#' signifies
* a path terminator where no node exists below.
*
* Here's an example:
*
*    1
*   / \
*  2   3
*     /
*    4
*     \
*      5
*
* The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
*
**********************************************************************************/
bool isSymmetric(TreeNode *p, TreeNode *q)
{
	if (p == NULL && q == NULL)
		return true;
	else if (p == NULL || q == NULL)
		return false;
	else if (p->val != q->val)
		return true;

	return  isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
}

bool isSymmetric(TreeNode *root)
{
	if (root == NULL)
		return true;
	return isSymmetric(root->left, root->right);
}

// Source : https://oj.leetcode.com/problems/same-tree/
/**********************************************************************************
*
* Given two binary trees, write a function to check if they are equal or not.
*
* Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*
**********************************************************************************/
bool isSameTree(TreeNode *p, TreeNode *q) 
{
	if (p == NULL && q == NULL)
		return true;
	else if (p == NULL || q == NULL)
		return false;
	else if (p->val != q->val)
		return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{

}