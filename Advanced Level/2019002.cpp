#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n, m;
    int arr[10005];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    int rows = ceil(n * 1.0 / m);
    for (int i = 0; i < rows; i++)
    {
        int t = (i + 1) * m > n ? n - i * m : m; // 用于处理最后一行个数不足的情况
        if (i % 2 == 0)                          // 奇数行顺序
        {
            for (int j = 1; j <= t; j++)
            {
                if (j != t)
                    cout << arr[i * m + j] << " ";
                else
                    cout << arr[i * m + j] << endl;
            }
        }
        else // 偶数行逆序
        {
            for (int j = t; j >= 1; j--)
            {
                if (j != 1)
                    cout << arr[i * m + j] << " ";
                else
                    cout << arr[i * m + j] << endl;
            }
        }
    }
    return 0;
}