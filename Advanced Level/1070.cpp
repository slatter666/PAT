#include <iostream>
#include <algorithm>
using namespace std;

struct mooncake
{
    double inv; // 库存
    double pro; // 总利润
} rec[1005];

bool cmp(mooncake m1, mooncake m2)
{
    return m1.pro / m1.inv > m2.pro / m2.inv; // 单件利润从大到小排列
}

int main()
{
    int n, d, cnt = 0;
    double profit = 0;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> rec[i].inv;
    for (int i = 0; i < n; i++)
        cin >> rec[i].pro;

    sort(rec, rec + n, cmp);
    while (d > 0 && cnt < n)
    {
        if (d >= rec[cnt].inv)
            profit += rec[cnt].pro;
        else
            profit += d * rec[cnt].pro / rec[cnt].inv;
        d -= rec[cnt++].inv;
    }
    printf("%.2f", profit);
    return 0;
}