#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num[10];
	int first = 10;
	for (int i = 0; i < 10; i++)
	{
		cin >> num[i];
		if (i != 0 && num[i] != 0 && i < first)
		{
			first = i;
			num[i]--;
		}
	}

	cout << first;
	for (int i = 0; i < 10; i++)
	{
		if (num[i] != 0)
		{
			while (num[i]--)
			{
				cout << i;
			}
		}
	}
	return 0;
}