// Source : https://oj.leetcode.com/problems/valid-parentheses/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-01

/**********************************************************************************
*
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
* determine if the input string is valid.
*
* The brackets must close in the correct order, "()" and "()[]{}" are all valid
* but "(]" and "([)]" are not.
*
**********************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

bool isParenthesesPattern(char a, char b)
{
	return ((a == '(' && b == ')') ||
		(a == '[' && b == ']') ||
		(a == '{' && b == '}'));
}
bool isValid(string s)
{
	stack<char> ss;

	const size_t len = s.size();
	for (size_t i = 0; i < len; ++i)
	{
		const char c = s[i];
		if (c == '(' || c == '[' || c == '{')
		{
			ss.push(c);
		}
		else
		{
			if (ss.empty())
				return false;
			char t = ss.top();  ss.pop();
			if (!isParenthesesPattern(t, c))
				return false;
		}
	}

	return ss.empty();
}

int main()
{
	cout << isValid("") << "\n";
	cout << isValid("()") << "\n";
	cout << isValid("()[]{}") << "\n";
	cout << isValid("((){[]}{})") << "\n";
	cout << isValid("([)]") << "\n";
	cout << isValid("[") << "\n";
	cout << isValid("]]") << "\n";

	system("pause");
}