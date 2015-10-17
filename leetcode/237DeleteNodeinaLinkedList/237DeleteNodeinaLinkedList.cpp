// Source : https://leetcode.com/problemset/algorithms/
// Author : lizhenghn@gmail.com

/**********************************************************************************
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
the linked list should become 1 -> 2 -> 4 after calling your function.

说的有点隐晦，其实就是给定一个单链表中的某一节点，然后删掉该节点。
**********************************************************************************/
#include <stdio.h>
#include <time.h>
#include "../common/single_list.hpp"

class Solution
{
public:
    void deleteNode(ListNode* node)
    {
        if (node == NULL || node->next == NULL)
        {
            return;
        }

        ListNode *next = node->next;
        node->val = next->val;
        node->next = next->next;

        delete next;
    }
};

int main()
{
    {
        int a[] = { 1, 4, 3, 2, 5, 2 };
        ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
        printList(p);
        printf("------------------------\n");
    }
}