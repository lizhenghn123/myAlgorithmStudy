// Source : https://oj.leetcode.com/problems/merge-k-sorted-lists/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-03

/**********************************************************************************
*
* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*
**********************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include "../common/single_list.hpp"
using namespace std;

//struct ListNodeCmp
//{
//	bool operator()(ListNode *a, ListNode *b) 
//	{
//		return a->val > b->val;
//	}
//};

struct ListNodeCmp : public binary_function < ListNode *, ListNode *, bool >
{
	bool operator()(ListNode *a, ListNode *b)
	{
		return !(a->val < b->val);
	}
};

//之前一直不明白题意，原来就是k个有序链表的合并。参照之前两个有序链表合并的实现
ListNode* mergeKLists(vector<ListNode *> &lists)
{
	ListNode dummy(0);
	ListNode *p = &dummy;

	priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> queue;

	for (size_t i = 0; i < lists.size(); i++)   //将每个有序链表的第一个节点放进优先队列
	{
		if (lists[i] != NULL) 
		{
			queue.push(lists[i]);
		}
	}

	ListNode *node;
	while (!queue.empty()) 
	{
		node = queue.top();    queue.pop();

		p->next = node;
		p = node;

		if (node->next != NULL) 
		{
			queue.push(node->next);
		}
	}

	return dummy.next;
}


int main()
{
	ListNode node2(2);
	ListNode node1(1);
	ListNode node3(3);
	priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> queue;

	queue.push(&node2);
	queue.push(&node1);
	queue.push(&node3);
	while (!queue.empty())
	{
		ListNode *node;
		node = queue.top();    queue.pop();
		cout << node->val << "\n";
	}

	system("pause");
}