#include <iostream>
using namespace std;

int main()
{
	string str1, str2;
	int n, count = 0;
	cin >> str1 >> n;
	getchar();
	while (true)
	{
		getline(cin, str2);
		count++;
		if (str2 == "#")
			break;

		if (str2 == str1)
		{
			cout << "Welcome in" << endl;
			break;
		}
		else
			cout << "Wrong password: " << str2 << endl;

		if (count == n)
		{
			cout << "Account locked" << endl;
			break;
		}
	}
	return 0;
}