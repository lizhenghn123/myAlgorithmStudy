// Source : https://oj.leetcode.com/problems/string-to-integer-atoi/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-03

/**********************************************************************************
*
* Implement atoi to convert a string to an integer.
*
* Hint: Carefully consider all possible input cases. If you want a challenge,
*       please do not see below and ask yourself what are the possible input cases.
*
* Notes:
*   It is intended for this problem to be specified vaguely (ie, no given input specs).
*   You are responsible to gather all the input requirements up front.
*
*
* Requirements for atoi:
*
* The function first discards as many whitespace characters as necessary until the first
* non-whitespace character is found. Then, starting from this character, takes an optional
* initial plus or minus sign followed by as many numerical digits as possible, and interprets
* them as a numerical value.
*
* The string can contain additional characters after those that form the integral number,
* which are ignored and have no effect on the behavior of this function.
*
* If the first sequence of non-whitespace characters in str is not a valid integral number,
* or if no such sequence exists because either str is empty or it contains only whitespace
* characters, no conversion is performed.
*
* If no valid conversion could be performed, a zero value is returned. If the correct value
* is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648)
* is returned.
*
**********************************************************************************/
#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;

bool isNum(char c)
{
	return c >= '0' && c <= '9';
}

int my_atoi(const char *str)
{
	assert(str != NULL);

	const size_t len = strlen(str);
	size_t i = 0;
	while (*(str + i) == ' ')
	{
		i++;
	}
	bool negative = false;
	int sum = 0;
	for (; i < len; i++)
	{
		if (*(str + i) == '-' || *(str + i) == '+')
		{
			if (i == len - 1)  //last char
				return 0;
			else if (!isNum(*(str + i + 1)))
				return 0;
			negative = (*(str + i) == '-');
		}
		else if (!isNum(*(str + i)))
		{
			return negative ? (0 - sum) : sum;
		}
		else
		{
			int r = (*(str + i) - '0');
			if (!negative && sum > (INT_MAX - r) / 10)
				return INT_MAX;
			else if (negative && (0 - sum) < (INT_MIN + r) / 10)
				return INT_MIN;

			sum = sum * 10 + r;
		}
	}

	return negative ? (0 - sum) : sum;
}
int main()
{
	cout << atoi("1sds") << "\n";
	cout << atoi("     d") << "\n";
	cout << atoi("1f56") << "\n";
	cout << atoi("-1f56") << "\n";
	cout << atoi("-f56") << "\n";
	cout << atoi("f56") << "\n";
	cout << atoi("-156") << "\n";
	cout << atoi("156   ") << "\n";
	cout << atoi("-034") << "\n";
	cout << atoi("2147483647") << "\n";
	cout << atoi("21474836489") << "\n";
	cout << atoi("-2147483648") << "\n";
	cout << atoi("-21474836488") << "\n";
	cout << atoi("   +0 123") << "\n";    // 0
	////char *p = NULL;
	////cout << atoi(p) << "\n";
	cout << "---------------------------\n";

	cout << my_atoi("1sds") << "\n";
	cout << my_atoi("     d") << "\n";
	cout << my_atoi("1f56") << "\n";
	cout << my_atoi("-1f56") << "\n";
	cout << my_atoi("-f56") << "\n";
	cout << my_atoi("f56") << "\n";
	cout << my_atoi("-156") << "\n";
	cout << my_atoi("156   ") << "\n";
	cout << my_atoi("-034") << "\n";
	cout << my_atoi("2147483647") << "\n";
	cout << my_atoi("21474836489") << "\n";
	cout << my_atoi("-2147483648") << "\n";
	cout << my_atoi("-21474836488") << "\n";
	cout << my_atoi("   +0 123") << "\n";    // 0
	//cout << isalnum('d') << "\n";
	//cout << isalnum('-') << "\n";
	//cout << my_atoi("  -d") << "\n";
	system("pause");
}