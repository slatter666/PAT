#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, count = 0, max = 0;
	int num[100005] = {0};
	int copy[100005] = {0};
	int rec[100005] = {0};
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		copy[i] = num[i];
	}

	sort(copy, copy + n);
	for (int i = 0; i < n; i++)
	{
		if (num[i] == copy[i] && num[i] > max)
			rec[count++] = num[i];
		if (num[i] > max)
			max = num[i];
	}
	cout << count << endl;
	for (int i = 0; i < count; i++)
	{
		cout << rec[i];
		if (i != count - 1)
			cout << " ";
	}
	cout << endl;
	return 0;
}