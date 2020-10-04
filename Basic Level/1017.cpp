#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int b;
	cin >> str >> b;
	int rem = 0;
	if ((str[0] - '0') / b == 0 && str.size() == 1)
		cout << (str[0] - '0') / b << " " << str[0] - '0' << endl;
	else
	{
		for (int i = 0; i < str.size(); i++)
		{
			rem = rem * 10 + str[i] - '0';
			if (i == 0 && rem / b == 0)
				continue;
			else
				cout << rem / b;
			rem %= b;
		}
		cout << " " << rem << endl;
	}
	return 0;
}