#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include <vector>
#include <queue>
#include <stack>
using namespace std;

//Definition for binary tree
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//TODO 关于二叉树的都要写非递归的算法

int treeDepth(TreeNode *root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;

	int leftDepth = treeDepth(root->left);
	int rightDepth = treeDepth(root->right);

	return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// 前序遍历
void preorderTraversal(TreeNode *root, vector<int>& orders)
{
	if (root == NULL)
		return;

	orders.push_back(root->val);

	if (root->left)
		preorderTraversal(root->left, orders);
	if (root->right)
		preorderTraversal(root->right, orders);
}

vector<int> preorderTraversal(TreeNode *root)
{
	vector<int> orders;
	preorderTraversal(root, orders);
	return orders;
}


// 中序遍历
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

// 后序遍历
void postorderTraversal(TreeNode *root, vector<int>& orders)
{
	if (root == NULL)
		return;

	if (root->left)
		postorderTraversal(root->left, orders);
	if (root->right)
		postorderTraversal(root->right, orders);

	orders.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root)
{
	vector<int> orders;
	postorderTraversal(root, orders);
	return orders;
}

// 层次遍历
vector<int> levelorderTraversal(TreeNode *root)
{
	vector<int> orders;

	queue<TreeNode*> queue;
	queue.push(root);
	while (!queue.empty())
	{
		TreeNode *node = queue.front();
		queue.pop();

		orders.push_back(node->val);

		if (node->left)
			queue.push(node->left);
		if (node->right)
			queue.push(node->right);
	}

	return orders;
}

// 从有序升序序列中构造平衡二叉查找树
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

// 检查以root为根的二叉树是否是二叉查找树
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

#endif  /* BINARY_TREE_HPP */
