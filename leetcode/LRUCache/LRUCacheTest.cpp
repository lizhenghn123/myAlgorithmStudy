// Source : https://oj.leetcode.com/problems/lru-cache/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-05

/**********************************************************************************
*
* Design and implement a data structure for Least Recently Used (LRU) cache.
* It should support the following operations: get and set.
*
*    get(key) - Get the value (will always be positive) of the key if the key exists
*               in the cache, otherwise return -1.
*
*    set(key, value) - Set or insert the value if the key is not already present.
*                      When the cache reached its capacity, it should invalidate
*                      the least recently used item before inserting a new item.
*
**********************************************************************************/
#include <iostream>
#include "LRUCache.h"
using namespace std;


int main()
{
	LRUCache cache(1);

	cache.set(2, 1);
	cout << cache.get(2) << "\n";
	cache.set(3, 2);
	cout << cache.get(2) << "\n";
	cout << cache.get(3) << "\n";

	system("pause");
}