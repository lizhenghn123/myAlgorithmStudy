// Source : https://oj.leetcode.com/problems/remove-element/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-28

/**********************************************************************************
*
* Given an array and a value, remove all instances of that value in place and return the new length.
*
* The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*
**********************************************************************************/

int removeElement(int A[], int n, int elem)
{
	if (n <= 0)
		return n;

	int idx = 0;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] != elem)
			A[idx++] = A[i];
	}

	return idx;
}

int main()
{

}