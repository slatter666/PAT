#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10005], coin[10005];
bool choice[10005][110];

bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> coin[i];
	sort(coin + 1, coin + n + 1, cmp); // 从大到小排序
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >= coin[i]; j--)
		{
			if (dp[j] <= dp[j - coin[i]] + coin[i])
			{
				choice[i][j] = true;
				dp[j] = dp[j - coin[i]] + coin[i];
			}
		}
	}
	if (dp[m] != m)
		printf("No Solution");
	else
	{
		vector<int> arr;
		int v = m, index = n;
		while (v > 0)
		{
			if (choice[index][v] == true)
			{
				arr.push_back(coin[index]);
				v -= coin[index];
			}
			index--;
		}
		for (int i = 0; i < arr.size(); i++)
		{
			if (i != 0)
				printf(" ");
			printf("%d", arr[i]);
		}
	}
	return 0;
}