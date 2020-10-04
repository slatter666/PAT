#include <iostream>
using namespace std;

int main()
{
	int total, k, n1, b, t, n2;
	scanf("%d %d", &total, &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d %d %d", &n1, &b, &t, &n2);
		if (t > total)
			printf("Not enough tokens.  Total = %d.\n", total);
		else
		{
			if ((b == 0 && n2 < n1) || (b == 1 && n2 > n1))
			{
				total += t;
				printf("Win %d!  Total = %d.\n", t, total);
			}
			else
			{
				total -= t;
				printf("Lose %d.  Total = %d.\n", t, total);
			}
		}

		if (total == 0)
		{
			printf("Game Over.\n");
			break;
		}
	}
	return 0;
}