#include <iostream>
using namespace std;

int main()
{
	int kind[1005] = {0};
	int n, m, num, count = 0, max_num = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> num;
			kind[j] += num;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (kind[i] > max_num)
			max_num = kind[i];
	}

	cout << max_num << endl;
	for (int i = 1; i <= n; i++)
	{
		if (kind[i] == max_num)
		{
			count++;
			if (count > 1)
				cout << " ";
			cout << i;
		}
	}
	return 0;
}