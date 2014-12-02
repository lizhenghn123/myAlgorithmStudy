#include <iostream>
#include <vector>
#include <queue>
#include "../common/binary_tree.hpp"
using namespace std;

// Source : https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-01
/**********************************************************************************
*
* Given a binary tree, return the level order traversal of its nodes' values.
* (ie, from left to right, level by level).
*
* For example:
* Given binary tree {3,9,20,#,#,15,7},
*
*     3
*    / \
*   9  20
*     /  \
*    15   7
*
* return its level order traversal as:
*
* [
*   [3],
*   [9,20],
*   [15,7]
* ]
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
//由二叉树的层序遍历演变而来，增加每次对每一层的节点计数。
vector<vector<int> > levelOrder(TreeNode *root)
{
	if (root == NULL)
		return vector< vector<int> >();

	vector< vector<int> > result;
	queue<TreeNode*> queue;
	queue.push(root);
	int currLevelCount = 1;  // queue.size()
	int nextLevelCount = 0;
	vector<int> currLeveleOrder;

	while (!queue.empty())
	{
		TreeNode *node = queue.front(); queue.pop();
		currLeveleOrder.push_back(node->val);

		if (node->left)
		{
			++nextLevelCount;
			queue.push(node->left);
		}
		if (node->right)
		{
			++nextLevelCount;
			queue.push(node->right);
		}

		--currLevelCount;
		if (currLevelCount == 0)		      // 当前层的节点已遍历完成
		{
			result.push_back(currLeveleOrder);
			currLeveleOrder.clear();
			currLevelCount = nextLevelCount;  //对下一层的节点进行遍历
			nextLevelCount = 0;
		}
	}

	return result;
}

// Source : https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-01
/**********************************************************************************
*
* Given a binary tree, return the bottom-up level order traversal of its nodes' values.
* (ie, from left to right, level by level from leaf to root).
*
* For example:
* Given binary tree {3,9,20,#,#,15,7},
*
*     3
*    / \
*   9  20
*     /  \
*    15   7
*
* return its bottom-up level order traversal as:
*
* [
*   [15,7],
*   [9,20],
*   [3]
* ]
*
**********************************************************************************/
//同上，但插入时不进行push_back，而是result.insert(result.begin(), currLeveleOrder);
//不过不确定这样会不会导致空间复杂度或时间复杂度（vector元素移动）增加？？？ --- OK
vector<vector<int> > levelOrderBottom(TreeNode *root)
{
	if (root == NULL)
		return vector< vector<int> >();

	vector< vector<int> > result;
	queue<TreeNode*> queue;
	queue.push(root);
	int currLevelCount = 1;  // queue.size()
	int nextLevelCount = 0;
	vector<int> currLeveleOrder;

	while (!queue.empty())
	{
		TreeNode *node = queue.front(); queue.pop();
		currLeveleOrder.push_back(node->val);

		if (node->left)
		{
			++nextLevelCount;
			queue.push(node->left);
		}
		if (node->right)
		{
			++nextLevelCount;
			queue.push(node->right);
		}

		--currLevelCount;
		if (currLevelCount == 0)		      // 当前层的节点已遍历完成
		{
			result.insert(result.begin(), currLeveleOrder);
			currLeveleOrder.clear();
			currLevelCount = nextLevelCount;  //对下一层的节点进行遍历
			nextLevelCount = 0;
		}
	}

	return result;
}

void printVector2D(const vector<vector<int> >& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		const vector<int>& v = vec[i];
		for (size_t j = 0; j < v.size(); ++j)
		{
			cout << v[j] << ",";
		}
		cout << "\n";
	}
	cout << "---------------\n";
}

int main()
{
	system("pause");
}