#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int rec[10005] = {0};
	int n, num;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		rec[abs(num - i)]++;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (rec[i] >= 2)
			cout << i << " " << rec[i] << endl;
	}
	return 0;
}