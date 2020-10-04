#include <iostream>
using namespace std;

int main()
{
	string str;
	int sum = 0, count_one = 0, count_zero = 0;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			sum += str[i] - 'a' + 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			sum += str[i] - 'A' + 1;
	}

	while (sum != 0)
	{
		if (sum % 2 == 1)
			count_one++;
		else
			count_zero++;
		sum /= 2;
	}

	cout << count_zero << " " << count_one << endl;
	return 0;
}