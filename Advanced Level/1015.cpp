#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
	if (num <= 3)
		return num > 1;
	else if (num % 6 != 1 && num % 6 != 5)
		return false;

	int sq = sqrt(num);
	for (int i = 5; i <= sq + 1; i += 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return false;
	}
	return true;
}

int convert(int num, int radix)
{
	string str = "";
	while (num != 0)
	{
		str.insert(0, to_string(num % radix));
		num /= radix;
	}

	reverse(str.begin(), str.end());
	int result = 0;
	for (int i = 0; i < str.size(); i++)
	{
		result += (str[str.size() - 1 - i] - '0') * pow(radix, i);
	}
	return result;
}

int main()
{
	int num, radix;
	cin >> num;
	while (num > 0)
	{
		cin >> radix;
		int temp = convert(num, radix);
		if (isPrime(num) && isPrime(temp))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		cin >> num;
	}
	return 0;
}