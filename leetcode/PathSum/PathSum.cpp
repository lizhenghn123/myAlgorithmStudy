// Source : https://oj.leetcode.com/problems/path-sum/
// Source : https://oj.leetcode.com/problems/path-sum-ii/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-02
/**********************************************************************************
*
* Given a binary tree and a sum, determine if the tree has a root-to-leaf path
* such that adding up all the values along the path equals the given sum.
*
* For example:
* Given the below binary tree and sum = 22,
*
*               5
*              / \
*             4   8
*            /   / \
*           11  13  4
*          /  \      \
*         7    2      1
*
* return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*
* Secnod : 
* Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
* return
* 
* [
*    [5,4,11,2],
*    [5,8,4,5]
* ]
* 
**********************************************************************************/
#include <iostream>
#include <time.h>
#include "../common/binary_tree.hpp"

void printTree_level_order(TreeNode *root)
{
	queue<TreeNode*> q;
	q.push(root);
	while (q.size()>0){
		TreeNode* n = q.front();
		q.pop();
		if (n == NULL){
			cout << "# ";
			continue;
		}
		cout << n->val << " ";
		q.push(n->left);
		q.push(n->right);
	}
	cout << endl;
}

bool hasPathSum(TreeNode *root, const int expectSum, int& currentSum)
{
	if (root == NULL)
		return false;

	currentSum += root->val;

	bool leaf = (root->left == NULL && root->right == NULL);
	if (leaf && currentSum == expectSum)
	{
		return true;
	}
	else if (hasPathSum(root->left, expectSum, currentSum) || hasPathSum(root->right, expectSum, currentSum))
	{
		return true;
	}

	currentSum -= root->val;

	return false;
}

bool hasPathSum(TreeNode *root, int sum)
{
	int curr_sum = 0;
	return hasPathSum(root, sum, curr_sum);
}

void pathSum(TreeNode *root, const int expectSum, vector<vector<int> >& allPaths, vector<int>& currPath, int& currentSum)
{
	if (root == NULL)
		return ;

	currentSum += root->val;
	currPath.push_back(root->val);

	bool leaf = (root->left == NULL && root->right == NULL);
	if (leaf && currentSum == expectSum)
	{
		allPaths.push_back(currPath);
		//currPath.clear();    //do not do this
	}
	if (root->left)
		pathSum(root->left, expectSum, allPaths, currPath, currentSum);
	if (root->right)
		pathSum(root->right, expectSum, allPaths, currPath, currentSum);

	currentSum -= root->val;
	currPath.pop_back();
}

vector<vector<int> > pathSum(TreeNode *root, int sum)
{
	vector<vector<int> > allPaths;
	vector<int> currPath;
	int curr_sum = 0;
	pathSum(root, sum, allPaths, currPath, curr_sum);
	return allPaths;
}

void printVector2D(const vector<vector<int> >& vec2d)
{
	for (size_t i = 0; i < vec2d.size(); ++i)
	{
		const vector<int>& vec = vec2d[i];
		for (size_t j = 0; j < vec.size(); ++j)
			cout << vec[j] << " ";
		cout << "\n";
	}
}

int main()
{
	{
		int a[] = { 1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 8, 5, 0 };
		TreeNode* p = createTree(a, sizeof(a) / sizeof(int));
		printTree_level_order(p);

		cout << hasPathSum(p, 16) << "\n";
		cout << hasPathSum(p, 19) << "\n";
		cout << hasPathSum(p, 1000) << "\n";

		vector<vector<int> > vec = pathSum(p, 15);
		printVector2D(vec);
	}
	{
		int a[] = { 5, 4, 8, 11, 0, 13, 4, 7, 2, 0, 0, 5, 1 };
		TreeNode* p = createTree(a, sizeof(a) / sizeof(int));
		printTree_level_order(p);

		cout << hasPathSum(p, 22) << "\n";
		cout << hasPathSum(p, 220) << "\n";

		vector<vector<int> > vec = pathSum(p, 22);
		printVector2D(vec);
	}

	cout << "\n";
	system("pause");
}