#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr1[105], arr2[105];
	int n, i, j;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	for (int i = 0; i < n; i++)
		cin >> arr2[i];

	for (i = 0; i < n - 1 && arr2[i] <= arr2[i + 1]; i++);
	for (j = i + 1; j < n && arr1[j] == arr2[j]; j++);

	if (j == n)
	{
		cout << "Insertion Sort" << endl;
		sort(arr1, arr1 + i + 2);
	}
	else
	{
		cout << "Merge Sort" << endl;
		int k = 1, flag = 1;
		while (flag)
		{
			flag = 0;
			for (i = 0; i < n; i++)
			{
				if (arr1[i] != arr2[i])
					flag = 1;
			}
			k = k * 2;
			for (j = 0; j < n / k; j++)
				sort(arr1 + j * k, arr1 + (j + 1) * k);
			sort(arr1 + j * k, arr1 + n);
		}
	}

	for (i = 0; i < n; i++)
	{
		if (i != 0)
			cout << " ";
		cout << arr1[i];
	}
	return 0;
}