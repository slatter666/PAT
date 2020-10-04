#include <stdio.h>
using namespace std;

int main()
{
	int n, point;
	int grade[105] = {0};
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &point);
		grade[point]++;
	}

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &point);
		printf("%d", grade[point]);
		if (i != m - 1)
			printf(" ");
	}
	return 0;
}