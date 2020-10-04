#include <iostream>
#include <string>
using namespace std;

int main()
{
	string rec = "10X98765432";
	int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	int n, count = 0;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		int sum = 0;
		for (int i = 0; i < 17; i++)
		{
			sum += (str[i] - '0') * weight[i];
		}
		sum %= 11;

		if (rec[sum] != str[17])
		{
			count++;
			cout << str << endl;
		}
	}

	if (count == 0)
	{
		cout << "All passed" << endl;
	}
}