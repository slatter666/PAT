#include <iostream>
using namespace std;

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

int main()
{
	long long n, t;
	long long numerator1, denominator1;			// 输入数据的分子、分母
	long long numerator2 = 0, denominator2 = 1; // 结果的分子、分母
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld/%lld", &numerator1, &denominator1);
		numerator2 = numerator2 * denominator1 + numerator1 * denominator2;
		denominator2 = denominator1 * denominator2;

		t = gcd(numerator2, denominator2); // 测试点3:必须在这里面约分，否则会溢出报错
		numerator2 /= t;
		denominator2 /= t;
	}

	long long integer = numerator2 / denominator2;
	numerator2 = abs(numerator2 - (integer * denominator2));

	if (integer != 0)
	{
		cout << integer;
		if (numerator2 != 0)
			cout << " ";
	}
	if (numerator2 != 0)
		cout << numerator2 << "/" << denominator2 << endl;

	if (integer == 0 && numerator2 == 0) // 测试点4:结果为0的情况
		cout << 0 << endl;
	return 0;
}