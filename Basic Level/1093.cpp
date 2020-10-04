#include <iostream>
using namespace std;

int main()
{
	bool asc[128] = {0};
	string a, b, str;
	getline(cin, a);
	getline(cin, b);
	str = a + b;
	for (int i = 0; i < str.size(); i++)
	{
		if (!asc[(int)(str[i])])
		{
			cout << str[i];
			asc[(int)(str[i])] = true;
		}
	}
	return 0;
}