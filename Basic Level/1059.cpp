#include <iostream>
#include <iomanip>
#include <string.h>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
	if (num <= 3)
		return num > 1;

	if (num % 6 != 1 && num % 6 != 5)
		return false;

	int sq = sqrt(num);
	for (int i = 5; i <= sq; i += 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return false;
	}
	return true;
}

int main()
{
	int n, num;
	cin >> n;
	int rec[10005];

	for (int i = 0; i < 10005; i++)
		rec[i] = -1;

	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		if (i == 1)
			rec[num] = 0;

		else
		{
			if (isPrime(i))
				rec[num] = 1;
			else
				rec[num] = 2;
		}
	}

	int k;
	cin >> k;
	bool check[10005] = {0};
	for (int i = 0; i < k; i++)
	{
		cin >> num;
		if (rec[num] == -1)
			cout << setw(4) << setfill('0') << num << ": Are you kidding?" << endl;
		else
		{
			if (check[num])
			{
				cout << setw(4) << setfill('0') << num << ": Checked" << endl;
				continue;
			}
			else if (rec[num] == 0)
				cout << setw(4) << setfill('0') << num << ": Mystery Award" << endl;
			else if (rec[num] == 1)
				cout << setw(4) << setfill('0') << num << ": Minion" << endl;
			else
				cout << setw(4) << setfill('0') << num << ": Chocolate" << endl;
			check[num] = true;
		}
	}
	return 0;
}