// Source : https://oj.leetcode.com/submissions/detail/16903707/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-19
/**********************************************************************************
*
* Compare two version numbers version1 and version1.
* If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
*
* You may assume that the version strings are non-empty and contain only digits and the . character.
* The . character does not represent a decimal point and is used to separate number sequences.
* For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
*
* Here is an example of version numbers ordering:
*
* 0.1 < 1.1 < 1.2 < 13.37
* Credits:
* Special thanks to @ts for adding this problem and creating all test cases.
*
**********************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int compareVersion(string version1, string version2)
{
	size_t len1 = version1.size();
	size_t len2 = version2.size();
	size_t i = 0;
	size_t j = 0;

	while (i < len1 && j < len2)
	{
		size_t i2 = i;
		size_t j2 = j;
		while (i2 < len1 && version1[i2] != '.')
			i2++;
		while (j2 < len2 && version2[j2] != '.')
			j2++;

		while (version1[i] == '0')   // case : "01" == "1"
			i++;
		while (version2[j] == '0')
			j++;

		if (i2 - i == j2 - j)
		{
			while (i != i2)
			{
				if (version1[i] < version2[j])
					return -1;
				else if (version1[i] > version2[j])
					return 1;
				i++;
				j++;
			}
		}
		else if (i2 - i < j2 - j)
		{
			return -1;
		}
		else
		{
			return 1;
		}
		i++;
		j++;
	}

	if (i > len1 && j < len2)     // case "1.1" > "1"; "1.0" == "1"
	{
		while (j < len2)
		{
			if (version2[j] != '0' && version2[j] != '.')
				return -1;
			j++;
		}
		return 0;
	}
		
	else if (i < len1 && j > len2)
	{
		while (i < len1)
		{
			if (version1[i] != '0' && version1[i] != '.')
				return 1;
			i++;
		}
		return 0;
	}
	return 0;
}


int main()
{
	cout << compareVersion("0.0", "0.1") << "\n";
	cout << compareVersion("1.0", "2.1") << "\n";
	cout << compareVersion("2.3", "2.5") << "\n";
	cout << compareVersion("2.4", "2.45") << "\n";
	cout << compareVersion("2.45", "24.5") << "\n";
	cout << "--------------\n";

	cout << compareVersion("1.0", "0.1") << "\n";
	cout << compareVersion("2.2", "2.1") << "\n";
	cout << compareVersion("3.23", "2.5") << "\n";
	cout << compareVersion("12.4", "2.45") << "\n";
	cout << compareVersion("24.45", "24.5") << "\n";
	cout << "--------------\n";

	cout << compareVersion("1.1", "1.1") << "\n";
	cout << compareVersion("01", "1") << "\n";
	cout << "--------------\n";

	cout << compareVersion("1", "1.1") << "\n";
	cout << compareVersion("1.1", "1") << "\n";
	cout << compareVersion("1.0", "1") << "\n";

	cout << compareVersion(
		"19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000",
		"19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000") << "\n";

	system("pause");
}