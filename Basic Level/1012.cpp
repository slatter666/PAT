#include <iostream>
#include <numeric>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	int n, num;
	int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
	int suma4 = 0, count = 0;
	cin >> n;
	while (n--)
	{
		cin >> num;
		if (num % 5 == 0 && num % 2 == 0)
			a1 += num;
		else if (num % 5 == 1)
		{
			count++;
			if (count % 2)
				a2 += num;
			else
				a2 -= num;
		}
		else if (num % 5 == 2)
		{
			a3++;
		}
		else if (num % 5 == 3)
		{
			suma4 += num;
			a4++;
		}
		else if (num % 5 == 4)
		{
			if (num > a5)
				a5 = num;
		}
	}

	if (a1 == 0)
		cout << "N ";
	else
		cout << a1 << " "; //输出a1

	if (count == 0)
		cout << "N ";
	else
		cout << a2 << " "; //输出a2

	if (a3 == 0)
		cout << "N ";
	else
		cout << a3 << " "; //输出a3

	if (a4 == 0)
		cout << "N ";
	else
		cout << setiosflags(ios::fixed) << setprecision(1) << 1.0 * suma4 / a4 << " ";  //输出a4,主要是这一行会导致过不了测试点 

	if (a5 == 0)
		cout << "N" << endl;
	else
		cout << a5 << endl; //输出a5

	return 0;
}