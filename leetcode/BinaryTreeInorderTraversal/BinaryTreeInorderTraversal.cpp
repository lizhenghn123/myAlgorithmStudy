// Source : https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-30

/**********************************************************************************
*
* Given a binary tree, return the inorder traversal of its nodes' values.
*
* For example:
* Given binary tree {1,#,2,3},
*
*    1
*     \
*      2
*     /
*    3
*
* return [1,3,2].
*
* Note: Recursive solution is trivial, could you do it iteratively?
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
*
**********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

 //Definition for binary tree
 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

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

 vector<int> inorderTraversal(TreeNode *root)
 {
	 vector<int> orders;
	 inorderTraversal(root, orders);
	 return orders;
 }

 int main()
 {

	 system("pause");
 }