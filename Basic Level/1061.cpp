#include <iostream>
using namespace std;

int main()
{
	int n, m;
	int point[105] = {0};
	int check[105] = {0};
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> point[i];

	for (int i = 0; i < m; i++)
		cin >> check[i];

	int ans, sum;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> ans;
			if (ans == check[j])
				sum += point[j];
		}
		cout << sum << endl;
	}
	return 0;
}