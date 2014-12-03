// Source : https://oj.leetcode.com/problems/copy-list-with-random-pointer/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-03

/**********************************************************************************
*
* A linked list is given such that each node contains an additional random pointer
* which could point to any node in the list or null.
*
* Return a deep copy of the list.
*
**********************************************************************************/
#include <iostream>
#include <unordered_map>
using namespace std;

struct RandomListNode 
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}	
};

RandomListNode* copyRandomList(RandomListNode *head)
{
	if (head == NULL)
		return NULL;

	RandomListNode dummy(0);
	RandomListNode *p = &dummy;

	unordered_map<RandomListNode*, RandomListNode*> map;

	RandomListNode *q = head;
	while (q)
	{
		RandomListNode *node = new RandomListNode(q->label);
		p->next = node;
		p = node;
		map.insert(std::make_pair(q, node));
		q = q->next;
	}

	q = head;
	while (q)
	{
		if (q->random == NULL)
			map[q]->random = NULL;
		else
			map[q]->random = map[q->random];   // just so : diff(q, q->random) = diff(map[q]->random, q->random)

		q = q->next;
	}

	return dummy.next;
}

void ttt(int &r)
{
	printf("%0x\n", &r);
	//printf("%0x\n", r);
	r++;
}
int main()
{
	int iii = 1;
	ttt(iii);

	int* p = NULL;
	int& r = *p;
	printf("%0x\n", p);
	//printf("%0x\n", *p);
	//printf("%0x\n", r);
	printf("%0x\n", &r);
	ttt(r);

	system("pause");
}