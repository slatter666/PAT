#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	string result = to_string(a * b);
	reverse(result.begin(), result.end());
	cout << stoi(result) << endl;
	return 0;
}