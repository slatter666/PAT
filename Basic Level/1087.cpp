#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		s.insert(i / 2 + i / 3 + i / 5);
	cout << s.size() << endl;
}