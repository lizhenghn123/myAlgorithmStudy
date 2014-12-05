// Source : https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-03

/**********************************************************************************
*
* Given preorder and inorder traversal of a tree, construct the binary tree.
*
* Note:
* You may assume that duplicates do not exist in the tree.
*
**********************************************************************************/
#include <iostream>
#include "../common/binary_tree.hpp"
using namespace std;

TreeNode* buildTree2(vector<int> &preorder, vector<int> &inorder)   // Memory Limit Exceeded ： 下面使用太多临时vector了
{
	const size_t prelen = preorder.size();
	const size_t inlen = inorder.size();

	if (prelen == 0 || prelen != inlen)
		return NULL;
	else if (prelen == 1)
		return new TreeNode(preorder[0]);

	TreeNode *root = new TreeNode(preorder[0]);

	int rootindex = inlen;
	for (size_t i = 0; i < inlen; ++i)    //find root index in inorder
	{
		if (inorder[i] == preorder[0])
		{
			rootindex = i;
			break;
		}
	}
	
	if (rootindex < inlen)     // root->left exist
	{
		vector<int> left_preorder, left_inorder;
		left_inorder.assign(inorder.begin(), inorder.begin() + rootindex);
		left_preorder.assign(preorder.begin() + 1, preorder.begin() + 1 + rootindex);
		root->left = buildTree2(left_preorder, left_inorder);
	}

	if (rootindex + 1 < inlen)  // root->right exist
	{
		vector<int> right_preorder, right_inorder;
		right_inorder.assign(inorder.begin() + rootindex + 1, inorder.end());
		right_preorder.assign(preorder.begin() + rootindex + 1, preorder.end());
		root->right = buildTree2(right_preorder, right_inorder);
	}

	return root;
}

// 上面递归实现的改进
// 假设preorder和inorder是可以正确构造出二叉树的，异常情况处理不完备
// prestart : 表示前序序列的起始位置，也即当前调用时的根节点
// instart  : 表示中序序列的起始位置，也即当前调用时的根节点的最左下叶节点
// len      : 表示当前调用时的子树序列长度
TreeNode* buildTree(const vector<int> &preorder, int prestart, const vector<int> &inorder, int instart, int len)
{
	if (len == 0)
		return NULL;
	else if (len == 1)
		return new TreeNode(preorder[prestart]);

	TreeNode *root = new TreeNode(preorder[prestart]);

	int rootindex = instart + len;
	for (size_t i = instart; i < instart + len; ++i)    //find root index in inorder
	{
		if (inorder[i] == preorder[prestart])
		{
			rootindex = i;
			break;
		}
	}

	int left_len = rootindex - instart;   // 以当前root为跟时，其左子树的长度

	// 注意下面递归调用时两个序列的索引的计算
	if (rootindex < instart + len)        // root->left exist
	{
		root->left = buildTree(preorder, prestart + 1, inorder, instart, left_len);
	}

	if (rootindex + 1 < instart + len)    // root->right exist
	{
		root->right = buildTree(preorder, prestart + left_len + 1, inorder, instart + left_len + 1, len - left_len - 1);
	}

	return root;
}

TreeNode* buildTree(const vector<int> &preorder, const vector<int> &inorder)
{
	const size_t prelen = preorder.size();
	const size_t inlen = inorder.size();

	if (prelen == 0 || prelen != inlen)
		return NULL;
	else if (prelen == 1)
		return new TreeNode(preorder[0]);

	int pre_left_len = 0;
	return buildTree(preorder, 0, inorder, 0, preorder.size());
}

void printVector(const vector<int>& vec)
{
	for (auto i : vec)
		cout << i << " ";
	cout << "\n------------\n";
}

int main()
{
	{
		vector<int> preorder = { 2, 1, 3 };
		vector<int>  inorder = { 1, 2, 3 };

		TreeNode* root = buildTree(preorder, inorder);

		vector<int> postorder = postorderTraversal(root);
		printVector(postorder);
	}
	{
		vector<int> preorder = { 6, 2, 1, 4, 3, 5, 7, 9, 8 };
		vector<int>  inorder = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		TreeNode* root = buildTree(preorder, inorder);

		vector<int> postorder = postorderTraversal(root);
		printVector(postorder);
	}
	{
		vector<int> preorder = { 2, 1, 3 };
		vector<int>  inorder = { 1, 2, 3 };

		TreeNode* root = buildTree2(preorder, inorder);

		vector<int> postorder = postorderTraversal(root);
		printVector(postorder);
	}
	{
		vector<int> preorder = { 6, 2, 1, 4, 3, 5, 7, 9, 8 };
		vector<int>  inorder = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		TreeNode* root = buildTree2(preorder, inorder);

		vector<int> postorder = postorderTraversal(root);
		printVector(postorder);
	}
	system("pause");
}