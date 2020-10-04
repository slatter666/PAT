#include <iostream>
using namespace std;

string solve(string s)
{
	string res;
	char rec = s[0];
	int count = 1;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == rec)
			count++;
		else
		{
			res += rec + to_string(count); //用res = res + rec + to_string(count)会超时
			rec = s[i];
			count = 1;
		}
	}
	res += rec + to_string(count);
	return res;
}

int main()
{
	int d, n;
	cin >> d >> n;
	string str = to_string(d);
	for (int i = 1; i < n; i++)
		str = solve(str);
	cout << str << endl;
}