#include <iostream>
using namespace std;

string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int h, m;
	bool flag1 = false;
	for (int i = 0; i < s1.size(); i++)
	{
		if (!flag1 && s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')
		{
			flag1 = true;
			cout << week[s1[i] - 'A'] << " ";
			continue;
		}
		if (flag1 && s1[i] == s2[i])
		{
			if (s1[i] >= 'A' && s1[i] <= 'N')
			{
				h = s1[i] - 'A' + 10;
				break;
			}
			if (s1[i] >= '0' && s1[i] <= '9')
			{
				h = s1[i] - '0';
				break;
			}
		}
	}

	for (int i = 0; i < s3.size(); i++)
	{
		if (s3[i] == s4[i] && ((s3[i] >= 'A' && s3[i] <= 'Z') || (s3[i] >= 'a' && s3[i] <= 'z')))
		{
			m = i;
			break;
		}
	}
	printf("%02d:%02d", h, m);
	return 0;
}