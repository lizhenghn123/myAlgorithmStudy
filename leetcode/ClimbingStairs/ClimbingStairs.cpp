// Source : https://oj.leetcode.com/problems/climbing-stairs/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-30

/**********************************************************************************
*
* You are climbing a stair case. It takes n steps to reach to the top.
*
* Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*
**********************************************************************************/
#include <stdio.h>

int climbStairs2(int n)    // Time Limit Exceeded
{
	if (n <= 1)
		return 1;

	return climbStairs2(n - 1) + climbStairs2(n - 2);
}

// a(n) = a(n-1) + a(n-2); a(0) = a(1) = 1
int climbStairs(int n)
{
	if (n <= 1)
		return 1;

	int current = 0;

	int next = 1;
	int nextnext = 1;
	for (int i = 2; i <= n; ++i)
	{
		current = next + nextnext;
		next = nextnext;
		nextnext = current;
	}

	return current;
}

int main()
{
	printf("%d\n", climbStairs2(1));
	printf("%d\n", climbStairs2(3));
	printf("%d\n", climbStairs(44));

	getchar();
}