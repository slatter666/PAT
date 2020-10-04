#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int rec[105], check[105];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> rec[i];

	for (int i = 1; i <= n; i++) //说对了相乘一定为正数,说假话相乘一定为负数
	{
		for (int j = i + 1; j <= n; j++)
		{
			int count1 = 0, count2 = 0; //说假话人数,狼人说假话人数
			fill(check, check + 105, 1);
			check[i] = check[j] = -1;
			for (int k = 1; k <= n; k++)
			{
				if (check[abs(rec[k])] * rec[k] < 0) //此人说谎话则count1加1
				{
					count1++;
					if (check[k] == -1) //说话的人确实是狼人则count2加1
						count2++;
				}
			}
			if (count1 == 2 && count2 == 1)
			{
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
	cout << "No Solution" << endl;
	return 0;
}