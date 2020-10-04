#include <iostream>
#include <string>
using namespace std;

int main()
{
	bool rec[128] = {0};
	string str1, str2;
	bool flag = false; //上档键情况
	getline(cin, str1);
	getline(cin, str2);
	for (int i = 0; i < str1.size(); i++)
	{
		if ((str1[i] >= '0' && str1[i] <= '9') || str1[i] == '_' || str1[i] == ',' || str1[i] == '.' || str1[i] == '-')
		{
			rec[(int)str1[i]] = 1;
		}
		else if (str1[i] == '+')
		{
			flag = true;
			rec[(int)str1[i]] = 1;
		}
		else if (str1[i] >= 'a' && str1[i] <= 'z')
		{
			rec[(int)str1[i]] = 1;
			rec[str1[i] - 32] = 1;
		}
		else if (str1[i] >= 'A' && str1[i] <= 'Z')
		{
			rec[(int)str1[i]] = 1;
			rec[str1[i] + 32] = 1;
		}
	}

	if (flag)
	{
		for (int i = 0; i < str2.size(); i++)
		{
			if ((str2[i] >= 'A' && str2[i] <= 'Z') || rec[(int)str2[i]])
				continue;
			else
				cout << str2[i];
		}
	}
	else
	{
		for (int i = 0; i < str2.size(); i++)
		{
			if (rec[(int)str2[i]])
				continue;
			else
				cout << str2[i];
		}
	}
}