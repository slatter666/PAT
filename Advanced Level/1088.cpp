#include <iostream>
using namespace std;

string zero = "0";

long long gcd(long long x, long long y)
{
	int temp = y;
	while (x % y != 0)
	{
		temp = x % y;
		x = y;
		y = temp;
	}
	return temp;
}

void format(long long x, long long y)
{
	if (x * y == 0) // x和y里面至少有一个为0
	{
		if (y == 0)
			cout << "Inf";
		else
			cout << "0";
		return;
	}
	else
	{
		bool flag = ((x < 0 && y > 0) || (x > 0 && y < 0));
		x = abs(x), y = abs(y);
		long long t = x / y;
		if (flag)
			cout << "(-";
		if (t != 0)
			cout << t;
		if (x % y == 0)
		{
			if (flag)
				cout << ")";
			return;
		}

		if (t != 0)
			cout << " ";
		x = x - y * t;
		long long res = gcd(x, y);
		x /= res, y /= res;
		cout << x << "/" << y;
		if (flag)
			cout << ")";
	}
}

int main()
{
	long long a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	format(a1, b1);cout << " + ";format(a2, b2);cout << " = ";format(a1 * b2 + a2 * b1, b1 * b2);cout << endl;
	format(a1, b1);cout << " - ";format(a2, b2);cout << " = ";format(a1 * b2 - a2 * b1, b1 * b2);cout << endl;
	format(a1, b1);cout << " * ";format(a2, b2);cout << " = ";format(a1 * a2, b1 * b2);cout << endl;
	format(a1, b1);cout << " / ";format(a2, b2);cout << " = ";format(a1 * b2, a2 * b1);cout << endl;
	return 0;
}