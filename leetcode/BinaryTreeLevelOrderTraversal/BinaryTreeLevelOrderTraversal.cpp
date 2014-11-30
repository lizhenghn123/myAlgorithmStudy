
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Definition for binary tree
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


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

int main()
{
	system("pause");
}