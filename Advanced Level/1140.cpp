#include <iostream>
using namespace std;

int main()
{
	string str;
	int n;
	cin >> str >> n;
	for (int i = 1; i < n; i++)
	{
		string stemp;
		char c = str[0];
		int count = 1;
		for (int j = 1; j < str.size(); j++)
		{
			if (str[j] != c)
			{
				stemp.push_back(c);
				stemp.append(to_string(count));
				c = str[j];
				count = 0;
			}
			count++;
		}
		stemp.push_back(c);
		stemp.append(to_string(count));
		str = stemp;
	}
	cout << str << endl;
	return 0;
}