#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n;
	cin >> n;
	int day[100005] = {0};
	for (int i = 1; i <= n; i++)
		cin >> day[i];

	sort(day + 1, day + n + 1, cmp);
	int ans = 0, index = 1;
	while (ans <= n && day[index] > index)
	{
		ans++;
		index++;
	}

	cout<<ans<<endl;
	return 0;
}