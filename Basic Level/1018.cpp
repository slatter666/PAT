#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n;
	char c1, c2;
	int per1[2][3]; //甲胜、平、负次数 及 B、C、J获胜次数
	int per2[2][3]; //乙胜、平、负次数 及 B、C、J获胜次数
	memset(per1, 0, sizeof(per1));
	memset(per2, 0, sizeof(per2));
	cin >> n;
	while (n--)
	{
		cin >> c1 >> c2;
		if (c1 == c2)
		{
			per1[0][1]++;
			per2[0][1]++;
		}
		else if (c1 == 'C')
		{
			if (c2 == 'J') //胜
			{
				per1[0][0]++;
				per1[1][1]++;

				per2[0][2]++;
			}
			else //负
			{
				per1[0][2]++;

				per2[0][0]++;
				per2[1][0]++;
			}
		}
		else if (c1 == 'J')
		{
			if (c2 == 'B') //胜
			{
				per1[0][0]++;
				per1[1][2]++;

				per2[0][2]++;
			}
			else //负
			{
				per1[0][2]++;

				per2[0][0]++;
				per2[1][1]++;
			}
		}
		else if (c1 == 'B')
		{
			if (c2 == 'C') //胜
			{
				per1[0][0]++;
				per1[1][0]++;

				per2[0][2]++;
			}
			else //负
			{
				per1[0][2]++;

				per2[0][0]++;
				per2[1][2]++;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		cout << per1[0][i];
		if (i != 2)
			cout << " ";
	}
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << per2[0][i];
		if (i != 2)
			cout << " ";
	}
	cout << endl;

	int max_count1 = 0, max_count2 = 0;
	int index1, index2;
	for (int i = 0; i < 3; i++)
	{
		if (per1[1][i] > max_count1)
		{
			max_count1 = per1[1][i];
			index1 = i;
		}
	}
	switch (index1)
	{
	case 0:
		cout << "B ";
		break;

	case 1:
		cout << "C ";
		break;

	case 2:
		cout << "J ";
		break;

	default:
		break;
	}

	for (int i = 0; i < 3; i++)
	{
		if (per2[1][i] > max_count2)
		{
			max_count2 = per2[1][i];
			index2 = i;
		}
	}
	switch (index2)
	{
	case 0:
		cout << "B";
		break;

	case 1:
		cout << "C";
		break;

	case 2:
		cout << "J";
		break;

	default:
		break;
	}

	return 0;
}