#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	string a, b;
	char d1, d2;
	int p1 = 0, p2 = 0;
	cin >> a >> d1 >> b >> d2;
	int num1 = d1 - '0';
	int num2 = d2 - '0';
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == d1)
		{
			p1 = p1 * 10 + num1;
		}
	}

	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == d2)
		{
			p2 = p2 * 10 + num2;
		}
	}

	cout << p1 + p2 << endl;
	return 0;
}