// Source : https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Source : https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-03
/**********************************************************************************
*
* Given a binary tree
*
*     struct TreeLinkNode {
*       TreeLinkNode *left;
*       TreeLinkNode *right;
*       TreeLinkNode *next;
*     }
*
* Populate each next pointer to point to its next right node.
* If there is no next right node, the next pointer should be set to NULL.
*
* Initially, all next pointers are set to NULL.
*
* Note:
*
* You may only use constant extra space.
* You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
*
* For example,
* Given the following perfect binary tree,
*
*          1
*        /  \
*       2    3
*      / \  / \
*     4  5  6  7
*
* After calling your function, the tree should look like:
*
*          1 -> NULL
*        /  \
*       2 -> 3 -> NULL
*      / \  / \
*     4->5->6->7 -> NULL
*
*
**********************************************************************************/
/**********************************************************************************
*
* Follow up for problem "Populating Next Right Pointers in Each Node".
* What if the given tree could be any binary tree? Would your previous solution still work?
*
* Note:
* You may only use constant extra space.
*
* For example,
* Given the following binary tree,
*
*          1
*        /  \
*       2    3
*      / \    \
*     4   5    7
*
* After calling your function, the tree should look like:
*
*          1 -> NULL
*        /  \
*       2 -> 3 -> NULL
*      / \    \
*     4-> 5 -> 7 -> NULL
*
*
**********************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include "../common/binary_tree.hpp"
using namespace std;

struct TreeLinkNode 
{
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
};

// ������������ʵһ��˼·���ò�α����ķ�ʽ�������������Ҫ�����Ƿ������������������������
// �ɲ�α����㷨����������ڱ�����ÿһ��Ľڵ��ͶԸò�ڵ��nextָ����д���
void connect(TreeLinkNode *root)
{
	if (root == NULL)
		return;

	queue<TreeLinkNode*> queue;
	queue.push(root);
	int currLevelCount = 1;  // queue.size()
	int nextLevelCount = 0;
	vector<TreeLinkNode*> currLeveleOrder;

	while (!queue.empty())
	{
		TreeLinkNode *node = queue.front(); queue.pop();
		currLeveleOrder.push_back(node);

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
		if (currLevelCount == 0)		      // ��ǰ��Ľڵ��ѱ������
		{
			const size_t len = currLeveleOrder.size();
			for (size_t i = 0; i < len; ++i)          //������һ��ڵ��nextָ��
			{
				if (i == len - 1)  // last one
					currLeveleOrder[i]->next = NULL;
				else
					currLeveleOrder[i]->next = currLeveleOrder[i + 1];
			}
			currLeveleOrder.clear();
			currLevelCount = nextLevelCount;  //����һ��Ľڵ���б���
			nextLevelCount = 0;
		}
	}
}

int main()
{
	system("pause");
}