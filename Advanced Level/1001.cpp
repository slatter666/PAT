#include <iostream>
using namespace std;

int main()
{
	int a, b, i, count = 0;
	cin >> a >> b;
	string s = to_string(a + b);
	for (int i = s.size() - 1; i >= 0; i--)
	{
		count++;
		if (count == 3 && s[i - 1] != '-' && i != 0)
		{
			count = 0;
			s.insert(i, ",");
		}
	}
	cout << s << endl;
	return 0;
}