#include <iostream>
#include <set>
using namespace std;

int main()
{
	int m, n, s, count = 0;
	cin >> m >> n >> s;
	string str;
	set<string> rec;

	if (s > m)
	{
		cout << "Keep going..." << endl;
		return 0;
	}

	for (int i = 0; i < m; i++)
	{
		count++;
		cin >> str;
		if (count == s)
		{
			if (rec.find(str) == rec.end())
			{

				cout << str << endl;
				rec.insert(str);
				s += n;
			}
			else
				s += 1;
		}
	}
	return 0;
}