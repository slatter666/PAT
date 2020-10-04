#include <iostream>
#include <string>
using namespace std;

int main()
{
	int rec[128] = {0};
	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 0; i < str1.size(); i++)
	{
		rec[(int)str1[i]]++;
	}

	bool flag = true; //是否全部包含
	int count = 0;
	for (int i = 0; i < str2.size(); i++)
	{
		if (rec[(int)str2[i]] != 0)
			rec[(int)str2[i]]--;
		else
		{
			flag = false;
			count++;
		}
	}

	if (flag)
		cout << "Yes " << str1.size() - str2.size();
	else
		cout << "No " << count << endl;
	return 0;
}