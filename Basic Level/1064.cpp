#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n, sum, count = 0;
	string str;
	set<int> s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		sum = 0;
		for (int j = 0; j < str.size(); j++)
			sum += str[j] - '0';
		s.insert(sum);
	}

	cout << s.size() << endl;
	for (int num : s)
	{
		count++;
		cout << num;
		if (count != s.size())
			cout << " ";
	}
	cout << endl;
	return 0;
}