#include <iostream>
using namespace std;

int main()
{
	int m, n, a, b, k, val;
	scanf("%d %d %d %d %d", &m, &n, &a, &b, &k);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &val);
			if (val >= a && val <= b)
				printf("%03d", k);
			else
				printf("%03d", val);
			if (j != n - 1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}