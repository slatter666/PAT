#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n;
	double num[10005] = {0};
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);
	double sum = num[0];
	for (int i = 1; i < n; i++)
		sum = (sum + num[i]) / 2;

	cout << floor(sum) << endl;
}