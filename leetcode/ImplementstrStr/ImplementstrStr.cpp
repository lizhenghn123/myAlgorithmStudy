// Source : https://oj.leetcode.com/problems/implement-strstr/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-03
/**********************************************************************************
*
* Implement strStr().
*
* Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*
**********************************************************************************/
#include <iostream>
using namespace std;

//  ±º‰∏¥‘”∂»O(m *n)
/*******************************
O(nm) runtime, O(1) space ®C Brute force:

You could demonstrate to your interviewer that this problem can be solved using known efficient algorithms such as Rabin-Karp algorithm, KMP algorithm, 
and the Boyer- Moore algorithm. Since these algorithms are usually studied in an advanced algorithms class, it is sufficient to solve it using the most 
direct method in an interview ®C The brute force method.

The brute force method is straightforward to implement. We scan the needle with the haystack from its first position and start matching all subsequent 
letters one by one. If one of the letters does not match, we start over again with the next position in the haystack.

The key is to implement the solution cleanly without dealing with each edge case separately.
********************************/
int strStr(char *haystack, char *needle)
{
	if (haystack == NULL || needle == NULL)
		return -1;
	else if (*needle == '\0')
		return 0;

	const size_t len1 = strlen(haystack);
	const size_t len2 = strlen(needle);
	if (len1 < len2)
		return -1;

	for (size_t i = 0; i <= len1 - len2; i++)
	{
		size_t j;
		for (j = 0; j < len2; j++)
		{
			if (*(haystack + i + j) != *(needle + j))
				break;
		}
		if (j >= len2)
			return i;
	}

	return -1;
}

int main()
{
	cout << strStr("asdfgdfjg", "1234") << "\n";
	cout << strStr("asdfgdfjg", "dfg") << "\n";
	cout << strStr("asdfgdfjg", "jg") << "\n";
	system("pause");
}