#include <iostream>
#include <string>
using namespace std;

int getRoman(char c)
{
	switch (c)
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	}
}

int romanToInt(string s)   //error!!!!
{
	int ret = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		ret += getRoman(s[i]);
	}
	return ret;
}


// Source : https://oj.leetcode.com/problems/length-of-last-word/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-30
/**********************************************************************************
*
* Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
* return the length of last word in the string.
*
* If the last word does not exist, return 0.
*
* Note: A word is defined as a character sequence consists of non-space characters only.
*
* For example,
* Given s = "Hello World",
* return 5.
*
**********************************************************************************/
int lengthOfLastWord(const char *s)
{
	if (!s || !*s) return 0;

	int len = 0;
	int cnt = 0;

	for (; *s != '\0'; s++) 
	{
		if (isalpha(*s))
		{
			cnt++;
		}
		else
		{
			if (cnt>0)
				len = cnt;
			cnt = 0;
		}
	}

	return cnt > 0 ? cnt : len;
}

int main()
{
	//cout << romanToInt("0") << "\n";
	//cout << romanToInt("45") << "\n";
	//cout << romanToInt("3468") << "\n";
	cout << romanToInt("DCXXI") << "\n";
	cout << romanToInt("MCMXCVI") << "\n";  // 2216 ---> 1996

	cout << lengthOfLastWord("a") << "\n";
	cout << lengthOfLastWord("a ") << "\n";
	cout << lengthOfLastWord("123 45678 567") << "\n";
	cout << lengthOfLastWord("12345 678567") << "\n";
	cout << lengthOfLastWord("12345678567") << "\n";
	cout << lengthOfLastWord("12345678567  ") << "\n";
	cout << lengthOfLastWord("  ") << "\n";
	cout << lengthOfLastWord("") << "\n";

	system("pause");
}