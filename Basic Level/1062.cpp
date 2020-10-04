#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
	int result;
	int x = max(a, b), y = min(a, b);
	while (y != 0)
	{
		result = x % y;
		x = y;
		y = result;
	}
	return x;
}

int main()
{
	int n1, m1, n2, m2, k, count = 0;
	scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
	double num1 = n1 * 1.0 / m1;
	double num2 = n2 * 1.0 / m2;
	double res;
	for (int i = 1; i * 1.0 / k < max(num1, num2); i++)
	{
		res = i * 1.0 / k;
		if (res > min(num1, num2) && gcd(i, k) == 1)
		{
			if (count == 0)
				printf("%d/%d", i, k);
			else
				printf(" %d/%d", i, k);
			count++;
		}
	}
	return 0;
}