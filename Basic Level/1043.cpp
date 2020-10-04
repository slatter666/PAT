#include <iostream>
using namespace std;

int main()
{
	int rec[128] = {0};
	char c;
	while (cin >> c)
	{
		rec[(int)c]++;
	}

	while (rec['P'] || rec['A'] || rec['T'] || rec['e'] || rec['s'] || rec['t'])
	{
		if (rec['P'])
		{
			cout << 'P';
			rec['P']--;
		}
		if (rec['A'])
		{
			cout << 'A';
			rec['A']--;
		}
		if (rec['T'])
		{
			cout << 'T';
			rec['T']--;
		}
		if (rec['e'])
		{
			cout << 'e';
			rec['e']--;
		}
		if (rec['s'])
		{
			cout << 's';
			rec['s']--;
		}
		if (rec['t'])
		{
			cout << 't';
			rec['t']--;
		}
	}
	return 0;
}