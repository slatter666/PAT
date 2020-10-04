#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void compare(int t1, double t2) //这个地方t2也应该用double,否则测试点三依然过不了
{
	if (t1 > t2)
		cout << " Gai";
	else if (t1 == t2)
		cout << " Ping";
	else
		cout << " Cong";
}

int main()
{
	int m, x, y, second, first = 99; //m、x、y、乙、甲
	double third;					 //丙
	cin >> m >> x >> y;
	while (first != 9)
	{
		string s = to_string(first);
		reverse(s.begin(), s.end());
		second = stoi(s);
		third = abs(first - second) * 1.0 / x;
		if (second == third * y)
			break;
		first--;
	}

	if (first == 9)
		cout << "No Solution" << endl;
	else
	{
		cout << first;
		compare(m, first);
		compare(m, second);
		compare(m, third);
	}
	return 0;
}