// Source : https://oj.leetcode.com/problems/reverse-words-in-a-string/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-07
/**********************************************************************************
*
* Given an input string, reverse the string word by word.
*
* For example,
* Given s = "the sky is blue",
* return "blue is sky the".
*
*
* Clarification:
*
* What constitutes a word?
* A sequence of non-space characters constitutes a word.
* Could the input string contain leading or trailing spaces?
* Yes. However, your reversed string should not contain leading or trailing spaces.
* How about multiple spaces between two words?
* Reduce them to a single space in the reversed string.
*
**********************************************************************************/
#include <iostream>
#include <string>
using namespace std;

void reverseWords(string &s)
{
	if (s.empty())
		return;

	string ret;
	const char spliter = ' ';
	size_t prepos = 0;
	size_t pos;
	while ((pos = s.find(spliter, prepos)) != string::npos)
	{
		if (prepos == pos)
		{
			prepos += 1;
			continue;
		}
			
		//string t = s.substr(prepos, s.size() - prepos + 1);
		//cout << t << "\n";
		ret.insert(0, s.substr(prepos, pos - prepos + 1));
		prepos = pos;
		prepos += 1;
	}

	if (prepos < s.size())
	{
		string t = s.substr(prepos, s.size() - prepos);
		t += " ";
		ret.insert(0, t);
	}
	s = ret.substr(0, ret.size() - 1);
}

int main()
{
	{
		string s1 = "   ";
		reverseWords(s1);
		cout << s1 << "\n";
	}
	{
		string s1 = "the sky is blue";
		reverseWords(s1);
		cout << s1 << "\n";
	}

	system("pause");
}