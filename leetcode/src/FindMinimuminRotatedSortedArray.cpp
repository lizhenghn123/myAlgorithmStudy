// Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Author : lizhenghn@gmail.com
// Date   : 2015-05-12
#include <iostream>
#include <vector>
using namespace std;

/**********************************************************************************
leetcode 153

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
**********************************************************************************/
class Solution1
{
public:
	int findMin(vector<int>& nums)
	{
		size_t start = 0;
		size_t end = nums.size() - 1;
		while (start < end)
		{
			if (nums[end] >= nums[start])
				break;

			size_t mid = (start + end) / 2;
			if (nums[start] > nums[mid])
				end = mid;
			else
				start = mid + 1;
		}

		return nums[start];
	}
};


/**********************************************************************************
leetcode 154

Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
**********************************************************************************/
class Solution2
{
public:
	int findMin(vector<int>& nums)
	{
		size_t start = 0;
		size_t end = nums.size() - 1;
		while (start < end)
		{
			if (nums[end] == nums[start])
			{
				start++;
				continue;
			}
			else if (nums[end] > nums[start])
			{
				break;
			}

			size_t mid = (start + end) / 2;
			if (nums[start] > nums[mid])
				end = mid;
			else
				start = mid + 1;
		}

		return nums[start];
	}
};
int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(1);
	cout << Solution2().findMin(vec) << "\n";
	system("pause");
}