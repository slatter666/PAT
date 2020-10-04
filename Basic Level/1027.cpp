#include <iostream>
using namespace std;

int main()
{
	int num, remain, count = 1, used = 1; //count指层数，used指需要用的符号个数，remain指剩余数
	char c;
	cin >> num >> c;
	while (true)
	{
		int temp = used + (count * 2 + 1) * 2;
		if (temp > num)
		{
			remain = num - used;
			break;
		}
		else
		{
			used = temp;
			count++;
		}
	}

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int k = (count - i) * 2 - 1; k > 0; k--)
		{
			cout << c;
		}
		cout << endl;
	}

	for (int i = 1; i < count; i++)
	{
		for (int j = count - i - 1; j > 0; j--)
		{
			cout << " ";
		}
		for (int k = 0; k < i * 2 + 1; k++)
		{
			cout << c;
		}
		cout << endl;
	}
	cout << remain << endl;
	return 0;
}