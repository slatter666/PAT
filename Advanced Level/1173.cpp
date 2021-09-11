#include <iostream>
using namespace std;

int main()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    int land[n];
    for (int i = 0; i < n; i++)
        cin >> land[i];

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += land[j];
            if (sum <= m) // 少写个等号5个测试没过
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}