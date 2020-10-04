#include <iostream>
using namespace std;

int main()
{
	int n;
	string str;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		bool flag1 = false, flag2 = false, flag3 = false; //分别记录字母、数字、不合法字符
		getline(cin, str);
		if (str.size() < 6)
			cout << "Your password is tai duan le." << endl;
		else
		{
			for (int j = 0; j < str.size(); j++)
			{
				if (str[j] == '.')
					continue;
				else if ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z'))
					flag1 = true;
				else if ((str[j] >= '0' && str[j] <= '9'))
					flag2 = true;
				else
				{
					flag3 = true;
					break;
				}
			}

			if (flag3)
				cout << "Your password is tai luan le." << endl;
			else if (flag1 && flag2)
				cout << "Your password is wan mei." << endl;
			else if (flag1)
				cout << "Your password needs shu zi." << endl;
			else
				cout << "Your password needs zi mu." << endl;
		}
	}
	return 0;
}