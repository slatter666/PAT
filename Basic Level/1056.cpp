#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num[10] = {0};
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != i)
				sum += num[i] * 10 + num[j];
		}
	}

	cout << sum << endl;
	return 0;
}