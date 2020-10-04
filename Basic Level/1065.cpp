#include <iostream>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

int main()
{
	int lovers[100005];
	set<int> s;
	fill(lovers, lovers + 100005, -1);
	int n, m, a, b, check, count = 0;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		lovers[a] = b;
		lovers[b] = a;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> check;
		s.insert(check);
	}

	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++)
	{
		if (s.find(lovers[*it]) != s.end())
		{
			s.erase(*it);
			s.erase(lovers[*it]);
		}
	}

	cout << s.size() << endl;
	for (it = s.begin(); it != s.end(); it++)
	{
		count++;
		cout << setw(5) << setfill('0') << *it;
		if (count != s.size())
			cout << " ";
	}
	return 0;
}