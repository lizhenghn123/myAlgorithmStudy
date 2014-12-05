// Source : https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-03

/**********************************************************************************
*
* Given inorder and postorder traversal of a tree, construct the binary tree.
*
* Note:
* You may assume that duplicates do not exist in the tree.
*
**********************************************************************************/

#include <iostream>
#include <assert.h>
#include "../common/binary_tree.hpp"
using namespace std;

TreeNode* buildTree2(const vector<int> &inorder, const vector<int> &postorder)   // Memory Limit Exceeded
{
	const size_t inlen = inorder.size();
	const size_t postlen = postorder.size();

	if (inlen == 0 || inlen != postlen)
		return NULL;
	else if (inlen == 1)
		return new TreeNode(postorder[inlen - 1]);

	TreeNode *root = new TreeNode(postorder[inlen - 1]);

	int rootindex = inlen;
	for (size_t i = 0; i < inlen; ++i)    //find root index in inorder
	{
		if (inorder[i] == postorder[inlen - 1])
		{
			rootindex = i;
			break;
		}
	}

	vector<int> in_order, post_order;
	if (rootindex < inlen)     // root->left exist
	{
		in_order.assign(inorder.begin(), inorder.begin() + rootindex);
		post_order.assign(postorder.begin(), postorder.begin() + rootindex);
		root->left = buildTree2(in_order, post_order);
	}

	if (rootindex + 1 < inlen)  // root->right exist
	{
		//in_order.clear();
		//post_order.clear();
		//in_order.shrink_to_fit();
		//post_order.shrink_to_fit();
		in_order.assign(inorder.begin() + rootindex + 1, inorder.end());
		post_order.assign(postorder.begin() + rootindex, postorder.end() - 1); //不包含最后一个节点（根）
		root->right = buildTree2(in_order, post_order);
	}

	//// this is ok， but Memory Limit Exceeded
	//if (rootindex < inlen)     // root->left exist
	//{
	//	vector<int> left_inorder, left_postorder;
	//	left_inorder.assign(inorder.begin(), inorder.begin() + rootindex);
	//	left_postorder.assign(postorder.begin(), postorder.begin() + rootindex);
	//	root->left = buildTree2(left_inorder, left_postorder);
	//}

	//if (rootindex + 1 < inlen)  // root->right exist
	//{
	//	vector<int> right_inorder, right_preorder;
	//	right_inorder.assign(inorder.begin() + rootindex + 1, inorder.end());
	//	right_preorder.assign(postorder.begin() + rootindex , postorder.end() -1); //不包含最后一个节点（根）
	//	root->right = buildTree2(right_inorder, right_preorder);
	//}

	return root;
}

// 上面递归实现的改进
// 假设inorder和postorder是可以正确构造出二叉树的，异常情况处理不完备
// instart  : 表示中序序列的起始位置，也即当前调用时的根节点的最左下叶节点
// postend  : 表示后序序列的最终位置，也即当前调用时的根节点
// len      : 表示当前调用时的子树序列长度
// 注意下面递归调用时对左右两个子树对应两个序列的索引计算方式
TreeNode* buildTree(const vector<int> &inorder, int instart, const vector<int> &postorder, int postend, int len)
{
	if (len == 0)
		return NULL;
	else if (len == 1)
	{
		assert(inorder[instart] == postorder[postend]);
		return new TreeNode(postorder[postend]);
	}

	TreeNode *root = new TreeNode(postorder[postend]);

	int rootindex = instart + len;
	for (size_t i = instart; i < instart + len; ++i)    //find root index in inorder
	{
		if (inorder[i] == postorder[postend])
		{
			rootindex = i;
			break;
		}
	}

	int left_len = rootindex - instart;   // 以当前root为跟时，其左子树的长度
	int right_len = len - left_len - 1;   // 以当前root为跟时，其右子树的长度

	// 注意下面递归调用时两个序列的索引的计算
	if (left_len >0 && (rootindex < instart + len))        // root->left exist
	{
		root->left = buildTree(inorder, instart, postorder, postend - len + left_len , left_len);  //param 3 :  逆推左子树的跟
	}

	if (right_len > 0 && (rootindex + 1 < instart + len))    // root->right exist
	{
		root->right = buildTree(inorder, instart + left_len + 1, postorder, postend - 1, right_len);
	}

	return root;
}


TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
	const size_t postlen = postorder.size();
	const size_t inlen = inorder.size();

	if (postlen == 0 || postlen != inlen)
		return NULL;
	else if (postlen == 1)
		return new TreeNode(postorder[0]);

	int pre_left_len = 0;
	return buildTree(inorder, 0, postorder, postorder.size() - 1, postorder.size());
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
		vector<int>  inorder = { -4, -10, 3, -1, 7, 11, -8, 2 };
		vector<int> postorder = { -4, -1, 3, -10, 11, -8, 2, 7 };

		TreeNode* root = buildTree(inorder, postorder);

		vector<int> preorder = preorderTraversal(root);
		printVector(preorder);   // 2 1 3
	}
	{
		vector<int>  inorder = { 1, 2, 3, 4 };
		vector<int> postorder = { 3, 2, 4, 1 };

		TreeNode* root = buildTree(inorder, postorder);

		vector<int> preorder = preorderTraversal(root);
		printVector(preorder);   // 2 1 3
	}
	{
		vector<int>  inorder = { 1, 2, 3 };
		vector<int> postorder = { 1, 3, 2 };

		TreeNode* root = buildTree(inorder, postorder);

		vector<int> preorder = preorderTraversal(root);
		printVector(preorder);   // 2 1 3
	}
	{
		vector<int>  inorder = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		vector<int> postorder = { 1, 3, 5, 4, 2, 8, 9, 7, 6 };

		TreeNode* root = buildTree2(inorder, postorder);

		vector<int> preorder = preorderTraversal(root);
		printVector(preorder);   // 6, 2, 1, 4, 3, 5, 7, 9, 8
	}

		{
			vector<int>  inorder = { -4, -10, 3, -1, 7, 11, -8, 2 };
			vector<int> postorder = { -4, -1, 3, -10, 11, -8, 2, 7 };

			TreeNode* root = buildTree2(inorder, postorder);

			vector<int> preorder = preorderTraversal(root);
			printVector(preorder);   // 2 1 3
		}
	{
		vector<int>  inorder = { 1, 2, 3, 4 };
		vector<int> postorder = { 3, 2, 4, 1 };

		TreeNode* root = buildTree(inorder, postorder);

		vector<int> preorder = preorderTraversal(root);
		printVector(preorder);   // 2 1 3
	}
	{
		vector<int>  inorder  = { 1, 2, 3 };
		vector<int> postorder = { 1, 3, 2 };

		TreeNode* root = buildTree2(inorder, postorder);

		vector<int> preorder = preorderTraversal(root);
		printVector(preorder);   // 2 1 3
	}
	{
		vector<int>  inorder  = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		vector<int> postorder = { 1, 3, 5, 4, 2, 8, 9, 7, 6 };

		TreeNode* root = buildTree2(inorder, postorder);

		vector<int> preorder = preorderTraversal(root);
		printVector(preorder);   // 6, 2, 1, 4, 3, 5, 7, 9, 8
	}
	system("pause");
}