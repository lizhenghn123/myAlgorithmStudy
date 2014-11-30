
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

int main()
{
	system("pause");
}