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

//֮ǰһֱ���������⣬ԭ������k����������ĺϲ�������֮ǰ������������ϲ���ʵ��
ListNode* mergeKLists(vector<ListNode *> &lists)
{
	ListNode dummy(0);
	ListNode *p = &dummy;

	priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> queue;

	for (size_t i = 0; i < lists.size(); i++)   //��ÿ����������ĵ�һ���ڵ�Ž����ȶ���
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