#include <iostream>
#include <cmath>
using namespace std;

void convert(string s, int t[])
{
	for (int i = s.size() - 1; i >= 0; i--)
		t[s.size() - i - 1] = s[i] - '0';
}

int main()
{
	int list[25], num1[25] = {0}, num2[25] = {0}, result[25] = {0};
	fill(list, list + 25, 10);
	string str, str1, str2;
	cin >> str >> str1 >> str2;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] - '0' != 0)
			list[str.size() - i - 1] = str[i] - '0';
	}
	convert(str1, num1);
	convert(str2, num2);

	int carry = 0, basic; //进位,本位
	int len = max(str1.size(), str2.size());

	for (int i = 0; i <= len; i++)
	{
		int sum = num1[i] + num2[i] + carry;
		carry = sum / list[i];
		basic = sum % list[i];
		result[i] = basic;
	}

	bool flag = false;
	for (int i = len; i >= 0; i--)
	{
		if (result[i] != 0)
			flag = true;

		if (flag)
			cout << result[i];
	}
	if (flag == false) //如果结果为0
		cout << 0 << endl;
	return 0;
}