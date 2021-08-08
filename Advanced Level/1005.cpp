#include <iostream>
using namespace std;

int main()
{
	string digit[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string num;
	int sum = 0;
	cin >> num;
	for (int i = 0; i < num.size(); i++)
		sum += num[i] - '0';

	string s = to_string(sum);
	for (int i = 0; i < s.size(); i++)
	{
		if (i != 0)
			cout << " ";
		cout << digit[s[i] - '0'];
	}
	return 0;
}