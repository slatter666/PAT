#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string str1, str2, str3, str4;
	cin >> str1 >> str2 >> str3 >> str4;
	int len1 = min(str1.size(), str2.size());
	bool flag1 = true, flag2 = false;
	for (int i = 0; i < len1; i++)
	{
		if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G' && flag1)
		{
			switch (str1[i] - 'A' + 1)
			{
			case 1:
				cout << "MON ";
				break;

			case 2:
				cout << "TUE ";
				break;

			case 3:
				cout << "WED ";
				break;

			case 4:
				cout << "THU ";
				break;

			case 5:
				cout << "FRI ";
				break;

			case 6:
				cout << "SAT ";
				break;

			case 7:
				cout << "SUN ";
				break;

			default:
				break;
			}
			flag1 = false;
			flag2 = true;
			continue;
		}

		if (flag2 && str1[i] == str2[i] && ((str1[i] >= 'A' && str1[i] <= 'N') || (str1[i] >= '0' && str1[i] <= '9')))
		{
			if (str1[i] >= 'A' && str1[i] <= 'N')
				cout << str1[i] - 'A' + 10 << ":";
			else
				cout << '0' << str1[i] - '0' << ":";
			break;
		}
	}

	int len2 = min(str3.size(), str4.size());
	for (int i = 0; i < len2; i++)
	{
		if (str3[i] == str4[i] && ((str3[i] >= 'a' && str3[i] <= 'z') || (str3[i] >= 'A' && str3[i] <= 'Z')))
		{
			cout << setw(2) << setfill('0') << i << endl;
		}
	}
	return 0;
}