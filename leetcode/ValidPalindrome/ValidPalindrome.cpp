// Source : https://oj.leetcode.com/problems/valid-palindrome/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-30

/**********************************************************************************
*
* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
*
* For example,
* "A man, a plan, a canal: Panama" is a palindrome.
* "race a car" is not a palindrome.
*
* Note:
* Have you consider that the string might be empty? This is a good question to ask during an interview.
*
* For the purpose of this problem, we define empty string as valid palindrome.
*
**********************************************************************************/
#include <iostream>
#include <string>
using namespace std;

bool isAlpha(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

bool isEqualNoCase(char a, char b)
{
	return a == b || a + 32 == b || b + 32 == a;
}

//回文数，只判断数字和字母，不区分大小写
bool isPalindrome(string s)
{
	if (s.empty())
		return true;

	int len = s.size();
	int begin = 0;
	int end = len - 1;

	while (begin < end)
	{
		while (begin < len && !isAlpha(s[begin]))
			begin++;
		if (begin >= end)
			return true;

		while (end > 0 && !isAlpha(s[end]))
			end--;
		if (begin >= end)
			return true;

		if (!isEqualNoCase(s[begin], s[end]))
			return false;

		begin++;
		end--;
	}

	return true;
}

int main()
{
	cout << isPalindrome("A man, a plan, a canal: Panama") << "\n";
	cout << isPalindrome("race a car") << "\n";
	cout << isPalindrome(".,") << "\n";    //true
	cout << isPalindrome("a,") << "\n";    //true
	cout << isPalindrome("aa") << "\n";    //true
	cout << isPalindrome("1a2") << "\n";    //false
	system("pause");
}