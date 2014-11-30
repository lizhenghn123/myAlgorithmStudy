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

int climbStairs(int n)    // Time Limit Exceeded
{
	if (n <= 1)
		return 1;

	return climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{
	printf("%d\n", climbStairs(1));
	printf("%d\n", climbStairs(3));
	printf("%d\n", climbStairs(44));

	getchar();
}