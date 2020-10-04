#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, p;
	cin >> n >> p;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int max_count = 0, j = 0;
	for (int i = 0; i < n; i++)
	{
		long long temp = arr[i];
		for (j; j < n; j++)
		{
			if (arr[j] > temp * p)
				break;
		}

		if (j - i > max_count)
			max_count = j - i;
	}
	cout << max_count << endl;
	return 0;
}