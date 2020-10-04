#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t; 
	double a, b, c;          //注意范围，不能用int，用long long也行
	for (int i = 1; i <= t; i++)
	{
		cin >> a >> b >> c;
		if (a + b > c)
			cout << "Case #" << i << ": true" << endl;
		else
			cout << "Case #" << i << ": false" << endl;
	}
	return 0;
}