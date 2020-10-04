#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

bool cmp(int x, int y)
{
	return x > y;
}

int solve(int num)
{
	if (num % 2 == 0)
		return num / 2;
	else
		return (3 * num + 1) / 2;
}

int main()
{
	int k;
	int matrix[105];

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> matrix[i];
	}

	for (int i = 0; i < k; i++)
	{
		if (matrix[i] != 0)
		{
			int rec = matrix[i];
			while (rec != 1)
			{
				rec = solve(rec);
				for (int j = 0; j < k; j++)
				{
					if (matrix[j] == rec)
						matrix[j] = 0;
				}
			}
		}
		else
			continue;
	}

	sort(matrix, matrix + k, cmp);
	for (int i = 0; i < k; i++)
	{
		if (matrix[i + 1] == 0)
		{
			cout << matrix[i] << endl;
			break;
		}
		else
		{
			cout << matrix[i] << " ";
		}
	}
	return 0;
}