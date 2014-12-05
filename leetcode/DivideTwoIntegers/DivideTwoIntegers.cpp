
#include <iostream>
using namespace std;

// TODO
int divide(int dividend, int divisor)       // Time Limit Exceeded
{
	bool negative = false;
	if (dividend < 0)
	{
		negative = !negative;
		dividend = -dividend;
	}
	if (divisor < 0)
	{
		negative = !negative;
		divisor = -divisor;
	}

	int ret = 0;
	while (dividend >= divisor)
	{
		dividend -= divisor;
		ret++;
	}

	return negative ? -ret : ret;
}

int main()
{
	cout << "10/2=" << divide(10, 2) << "\n";
	cout << "10/3=" << divide(10, 3) << "\n";
	cout << "10/5=" << divide(10, 5) << "\n";
	cout << "10/7=" << divide(10, 7) << "\n";
	cout << "10/10=" << divide(10, 10) << "\n";
	cout << "10/11=" << divide(10, 11) << "\n";
	cout << "1/-1=" << divide(1, -1) << "\n";
	cout << "-1/-1=" << divide(-1, -1) << "\n";
	cout << "2147483647/1=" << divide(2147483647, 1) << "\n";     // Time Limit Exceeded
	cout << "-2147483647/1=" << divide(-2147483647, 1) << "\n";
	cout << "2147483647/-1=" << divide(2147483647, -1) << "\n";
	cout << "-2147483647/-1=" << divide(-2147483647, -1) << "\n";
	cout << "2147483647/2=" << divide(2147483647, 2) << "\n";
	cout << "2147483647/10=" << divide(2147483647, 10) << "\n";
	//cout << "-2147483648/1=" << divide(-2147483648, 1) << "\n";

	system("pause");
}