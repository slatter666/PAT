#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int index = str.find('E');
	if (str[0] == '-')
		cout << "-";
	string num1 = str.substr(1, index - 1);
	int num2 = stoi(str.substr(index + 1));
	if (num2 <= 0)
	{
		int t = -num2;
		for (int i = 0; i < t; i++)
		{
			num1.insert(0, "0");
		}
		num1.erase(num1.find('.'), 1);
		num1.insert(1, ".");
	}
	else
	{
		int t = num1.substr(2).size() - num2;
		if (t <= 0)
		{
			for (int i = 0; i < -t; i++)
			{
				num1.append("0");
			}
			num1.erase(num1.find('.'), 1);
		}
		else
		{
			num1.erase(num1.find('.'), 1);
			num1.insert(num2 + 1, ".");
		}
	}
	cout << num1 << endl;
	return 0;
}