#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int p = 0, pa = 0, pat = 0;
	char c;
	while (cin >> c)
	{
		if (c == 'P')
			p++;
		else if (c == 'A')
			pa = (pa + p) % 1000000007;
		else
			pat = (pat + pa) % 1000000007;
	}
	cout << pat << endl;
	return 0;
}