// Source : https://leetcode.com/problems/happy-number/
// Author : lizhenghn@gmail.com
// Date   : 2015-05-11
/**********************************************************************************
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

	1^2 + 9^2 = 82
	8^2 + 2^2 = 68
	6^2 + 8^2 = 100
	1^2 + 0^2 + 0^2 = 1
**********************************************************************************/
#include <iostream>
using namespace std;

long getSum(long n)
{
	long sum = 0;
	while (n)
	{
		int x = n % 10;
		sum += x * x;
		n = n / 10;
	}
	return sum;
}


bool isHappy(int n)
{
	long s = getSum(n);
	if (s == 1)
		return true;
	else if (s < 10)
		return false;
	else
		return isHappy(s);
}
int main()
{
	cout << isHappy(7) << "\n";  // true 7 -- > 49 --> 
	cout << isHappy(19) << "\n";
	cout << isHappy(10) << "\n";
	cout << isHappy(12) << "\n";
	cout << isHappy(78) << "\n";
	cout << isHappy(7867) << "\n";
	system("pause");
}