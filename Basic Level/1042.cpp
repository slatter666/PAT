#include <iostream>
using namespace std;

int main()
{
	int rec[128] = {0};
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			rec[(int)str[i]]++;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			rec[str[i] + 32]++;
	}

	int index, max_num = 0;
	for (int i = 97; i <= 122; i++)
	{
		if (rec[i] > max_num)
		{
			index = i;
			max_num = rec[i];
		}
	}
	cout << char(index) << " " << max_num << endl;
	return 0;
}