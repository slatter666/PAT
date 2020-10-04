#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int num, int scale)
{
	vector<char> str;
	int result = num;
	if (num == 0)
		cout << 0 << endl;
	else
	{
		while (result != 0)
		{
			int remainder = result % scale; //余数
			result = result / scale;		//结果（下一次的被除数）
			str.push_back('0' + remainder);
		}
		reverse(str.begin(), str.end());
		for (int i = 0; i < str.size(); i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
}

int main()
{
	int a, b, d;
	cin >> a >> b >> d;
	solve(a + b, d);
	return 0;
}