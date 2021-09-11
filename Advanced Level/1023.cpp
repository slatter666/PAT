#include <iostream>
using namespace std;

int main()
{
	int check[10] = {0};
	int rec[25] = {0};
	string num;
	cin >> num;
	for (int i = 0; i < num.size(); i++)
	{
		rec[i + 1] = num[i] - '0';
		check[num[i] - '0'] += 1;
	}

	int carry = 0;
	for (int i = num.size(); i >= 0; i--)
	{
		int temp = rec[i] * 2 + carry;
		rec[i] = temp % 10;
		carry = temp / 10;
	}

	if (rec[0] != 0) // 只能这样判断,不能提前check[0]=1;
		check[rec[0]] -= 1;
	bool flag = true;
	for (int i = 1; i <= num.size(); i++)
	{
		check[rec[i]] -= 1;
		if (check[rec[i]] < 0)
			flag = false;
	}

	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	if (rec[0] != 0)
		cout << rec[0];
	for (int i = 1; i <= num.size(); i++)
	{
		cout << rec[i];
	}
	return 0;
}