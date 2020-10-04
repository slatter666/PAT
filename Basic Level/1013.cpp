#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
	if (num <= 3)
		return num > 1;
	else if (num % 6 != 1 && num % 6 != 5)
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
	int m, n;
	cin >> m >> n;
	int count = 0, total = 0, i = 2;
	while (true)
	{
		if (isPrime(i))
		{
			total++;
			if (total >= m && total < n)
			{
				count++;
				if (count == 10)
				{
					cout << i << endl;
					count = 0;
				}
				else
				{
					cout << i << " ";
				}
			}
			else if (total == n)
			{
				cout << i << endl;
				break;
			}
		}
		i++;
	}
}