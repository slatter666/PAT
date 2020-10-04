#include <iostream>
using namespace std;

void compress(string s) //压缩
{
	char rec = s[0];
	int count = 1;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == rec)
			count++;
		else
		{
			if (count > 1)
				cout << count << rec;
			else
				cout << rec;
			rec = s[i];
			count = 1;
		}
	}
	if (count > 1)
		cout << count << rec;
	else
		cout << rec;
}

void decompression(string s) //解压
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			count = count * 10 + s[i] - '0';
		else
		{
			if (count == 0)
				cout << s[i];
			else
			{
				for (int j = 0; j < count; j++)
					cout << s[i];
			}
			count = 0;
		}
	}
}

int main()
{
	char c;
	string str;
	cin >> c;
	getchar();
	getline(cin, str);
	if (c == 'C')
		compress(str);
	else if (c == 'D')
		decompression(str);
	cout << endl;
	return 0;
}