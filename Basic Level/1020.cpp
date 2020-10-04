#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct mooncake
{
	double store;		//库存量
	double total_price; //总售价
	double unit_price;	//单价
};

bool cmp(mooncake m1, mooncake m2)
{
	return m1.unit_price > m2.unit_price;
}

int main()
{
	mooncake moon[1005];
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		cin >> moon[i].store;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> moon[i].total_price;
		moon[i].unit_price = moon[i].total_price / moon[i].store;
	}

	sort(moon, moon + n, cmp);

	int i = 0;
	double mon = 0;
	while (d != 0 && i < n)
	{
		if (d >= moon[i].store)
		{
			d -= moon[i].store;
			mon += moon[i].total_price;
		}
		else
		{
			mon += d * moon[i].unit_price;
			d = 0;
		}
		i++;
	}

	cout << setiosflags(ios::fixed) << setprecision(2) << mon << endl;
	return 0;
}
// 测试点2有坑  库存量和总售价都是可以不是整数