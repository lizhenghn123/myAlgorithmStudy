// Source : https://leetcode.com/problems/simplify-path/
// Author : lizhenghn@gmail.com
/**********************************************************************************
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
**********************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string simplifyPath(string path)
	{
		if (path.empty())
			return path;

		vector<string> vec;

		size_t idx = 0;
		size_t pre = idx;
		while (true)
		{
			idx = path.find_first_of("/", idx);
			if (idx == string::npos)
			{
				break;
			}

			string tmp = path.substr(pre, idx - pre);
			//cout << tmp << "\n";
			if (tmp.empty() || tmp == ".")
			{

			}
			else if (tmp == "..")
			{
				if (!vec.empty())
					vec.pop_back();
			}
			else
			{
				vec.push_back(tmp);
			}
			pre = ++idx;
		}

		if (pre < path.size())   // "/..." ---> "/..."
		{
			string tmp(path.substr(pre, path.size() - pre));
			if (tmp == ".")    // "/here/."  --- > "/here"
			{

			}
			else if (tmp == "..")     
			{
				if (!vec.empty())    ///eHx/..
					vec.pop_back();
			}
			else  // "/." ---> "/"; "/.." ---> "/"
			{
				vec.push_back(tmp);
			}
		}

		string ret;
		for (size_t i = 0; i < vec.size(); ++i)
		{
			ret += "/";
			ret += vec[i];
		}

		if (ret.empty())
			return "/";
		return ret;
	}
};

int main()
{
	cout << Solution().simplifyPath("/home/of/foo/../../bar/../../is/./here/.") << "\n";
	
	cout << Solution().simplifyPath("///eHx/..") << "\n";   // /
	cout << Solution().simplifyPath("/..") << "\n";   // /
	cout << Solution().simplifyPath("/.") << "\n";   // /
	cout << Solution().simplifyPath("/...") << "\n";   // /... not /
	cout << Solution().simplifyPath("/home/") << "\n";
	cout << Solution().simplifyPath("/a/./b/../../c/") << "\n";
	cout << Solution().simplifyPath("/../") << "\n";
	cout << Solution().simplifyPath("/home//foo/") << "\n";
	system("pause");
}