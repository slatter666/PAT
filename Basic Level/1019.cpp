#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int arr[4];

bool cmp(int x, int y)
{
	return x > y;
}

int sort1(int num) //非递增排序数字
{
	arr[0] = num / 1000; //千位
	num %= 1000;
	arr[1] = num / 100; //百位
	num %= 100;
	arr[2] = num / 10; //十位
	arr[3] = num % 10; //个位

	sort(arr, arr + 4, cmp);
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		result = result * 10 + arr[i];
	}
	return result;
}

int sort2(int num) //非递减排序数字
{
	arr[0] = num / 1000; //千位
	num %= 1000;
	arr[1] = num / 100; //百位
	num %= 100;
	arr[2] = num / 10; //十位
	arr[3] = num % 10; //个位

	sort(arr, arr + 4);
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		result = result * 10 + arr[i];
	}
	return result;
}

int main()
{
	int num;
	cin >> num;
	while (true)
	{
		int num1 = sort1(num);
		int num2 = sort2(num);
		num = num1 - num2;
		cout << setw(4) << setfill('0') << num1 << " - " << setw(4) << setfill('0') << num2 << " = " << setw(4) << setfill('0') << num << endl;
		if (num == 0)
			return 0;
		if (num == 6174)
			break;
	}
}