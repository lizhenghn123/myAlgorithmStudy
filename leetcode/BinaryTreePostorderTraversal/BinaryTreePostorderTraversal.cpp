
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