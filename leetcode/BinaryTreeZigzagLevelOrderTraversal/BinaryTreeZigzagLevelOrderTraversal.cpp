// Source : https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-03
/**********************************************************************************
*
* Given a binary tree, return the zigzag level order traversal of its nodes' values.
* (ie, from left to right, then right to left for the next level and alternate between).
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
* return its zigzag level order traversal as:
*
* [
*   [3],
*   [20,9],
*   [15,7]
* ]
*
**********************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include "../common/binary_tree.hpp"
using namespace std;

//由层次遍历改造而来，参见：https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
vector<vector<int> > zigzagLevelOrder(TreeNode *root)
{
	if (root == NULL)
		return vector< vector<int> >();

	vector< vector<int> > result;
	queue<TreeNode*> queue;
	queue.push(root);
	int currLevelCount = 1;  // queue.size()
	int nextLevelCount = 0;
	vector<int> currLeveleOrder;

	bool isOddLevel = true;
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
			if (!isOddLevel)
				std::reverse(currLeveleOrder.begin(), currLeveleOrder.end());
			isOddLevel = !isOddLevel;

			result.push_back(currLeveleOrder);
			currLeveleOrder.clear();
			currLevelCount = nextLevelCount;  //对下一层的节点进行遍历
			nextLevelCount = 0;
		}
	}

	return result;
}

int main()
{
	system("pause");
}