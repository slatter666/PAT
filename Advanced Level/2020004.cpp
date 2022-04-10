#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 100005;
int n, d, cnt = 0;
int prices[MAXN], coupons[MAXN];
struct node
{
    int i, j;
    friend bool operator<(node n1, node n2)
    {
        return prices[n1.i] - coupons[n1.j] > prices[n2.i] - coupons[n2.j]; // 队头最小
    }
};

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> coupons[i];

    sort(prices, prices + n);        // 价格从小到大排序
    sort(coupons, coupons + n, cmp); // 优惠券从大到小排序
    priority_queue<node> q;
    for (int i = 0; i < n; i++)
        q.push({i, 0});

    while (d > 0 && !q.empty())
    {
        node temp = q.top();
        q.pop();
        int cost = prices[temp.i] - coupons[temp.j];
        if (d >= cost) // 少写了个等号调试了好久
        {
            d -= cost;
            cnt++;
            if (temp.j != n - 1) // 对于该商品已经没有优惠券可以用了
            {
                temp.j++;
                q.push(temp);
            }
        }
        else
            break; // 已经买不起了，后面的优惠券面值更小更买不起
    }
    cout << cnt << " " << d << endl;
    return 0;
}