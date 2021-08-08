#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

struct station
{
    double price;
    double mile;
} rec[510];

bool cmp(station s1, station s2)
{
    return s1.mile < s2.mile;
}

int main()
{
    int cmax, dist, avg, n;
    cin >> cmax >> dist >> avg >> n;
    rec[0] = {0.0, double(dist)}; // 终点
    for (int i = 1; i <= n; i++)
        cin >> rec[i].price >> rec[i].mile;

    sort(rec, rec + n + 1, cmp);
    double nowPos = 0.0, maxPos = 0.0, nowPrice = 0.0, totalPrice = 0.0, remain = 0.0; // 当前位置、所能到的最远位置、当前站点价格、油箱还有多少油
    if (rec[0].mile != 0)                                                              // 起点不允许加油
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    else
        nowPrice = rec[0].price;

    while (nowPos < dist)
    {
        maxPos = nowPos + cmax * avg; // 当前装满油能到达的最远距离
        double minPriceDist = 0, minPrice = INF;
        bool flag = false;
        for (int i = 1; i <= n && rec[i].mile <= maxPos; i++) // 在范围区间找到比当前油价低的最近加油站，若没有则找区间中最低的
        {
            if (rec[i].mile <= nowPos)
                continue;
            if (rec[i].price < nowPrice) // 能找到比当前价格更低的加油站
            {
                totalPrice += nowPrice * ((rec[i].mile - nowPos) / avg - remain); // 当前油价*所需油量
                remain = 0;
                nowPrice = rec[i].price;
                nowPos = rec[i].mile;
                flag = true;
                break;
            }
            else // 找不到比当前价格更低的加油站
            {
                if (rec[i].price < minPrice)
                {
                    minPrice = rec[i].price;
                    minPriceDist = rec[i].mile;
                }
            }
        }
        if (!flag && minPrice != INF) // 找不到比当前价格更低的加油站，但是周围还有加油站可以加油，开过去加满
        {
            totalPrice += nowPrice * (cmax - remain);      //   把油加满，自己举一个油价一直增的情况就懂这两行代码了
            remain = cmax - (minPriceDist - nowPos) / avg; // 当前站把油加满，抵达下一站还剩多少油
            nowPrice = minPrice;
            nowPos = minPriceDist;
        }
        if (!flag && minPrice == INF) // 周围可达距离没有加油站可以加油，到不了终点，也就是说上面的for循环体的if-else是根本不会进去的
        {
            printf("The maximum travel distance = %.2f", nowPos + cmax * avg);
            return 0;
        }
    }
    printf("%.2f", totalPrice);
    return 0;
}