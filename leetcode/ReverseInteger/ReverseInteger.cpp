// Source : https://oj.leetcode.com/problems/reverse-integer/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-30

/**********************************************************************************
*
* Reverse digits of an integer.
*
* Example1: x =  123, return  321
* Example2: x = -123, return -321
*
*
* Have you thought about this?
*
* Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
*
* > If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
*
* > Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer,
*   then the reverse of 1000000003 overflows. How should you handle such cases?
*
* > Throw an exception? Good, but what if throwing an exception is not an option?
*   You would then have to re-design the function (ie, add an extra parameter).
*
**********************************************************************************/
#include <stdio.h>
#include <math.h>
#include <limits.h>  // for INT_MAX

int reverse(int x)
{
	int y = 0;
	while (x)
	{
		if (y > INT_MAX / 10 || y < INT_MIN / 10)
			return 0;
		y = y * 10 + x % 10;
		x = x / 10;
	}
	return y;
}

int main()
{
	printf("%d\n", reverse(100));
	printf("%d\n", reverse(-100));
	printf("%d\n", reverse(2147483647));
	printf("%d\n", reverse(-2147483647));

	getchar();
}