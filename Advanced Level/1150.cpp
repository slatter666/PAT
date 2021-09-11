#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m, city1, city2, dist, k, ans = 99999999, ansid;
int rec[205][205];

void check(int index)
{
    int sum = 0, cnt, flag = 1;
    cin >> cnt;
    vector<int> vec(cnt);
    set<int> s;
    for (int i = 0; i < cnt; i++)
    {
        cin >> vec[i];
        s.insert(vec[i]);
    }

    for (int i = 0; i < cnt - 1; i++)
    {
        if (rec[vec[i]][vec[i + 1]] == 0) // 无路径
            flag = 0;
        sum += rec[vec[i]][vec[i + 1]];
    }
    if (flag == 0) // 非旅行商环路,路径不存在
        printf("Path %d: NA (Not a TS cycle)\n", index);
    else if (vec[0] != vec[cnt - 1] || s.size() != n) // 非旅行商环路，路径存在
        printf("Path %d: %d (Not a TS cycle)\n", index, sum);
    else if (cnt != n + 1) // 旅行商环路，非简单旅行商环路
    {
        printf("Path %d: %d (TS cycle)\n", index, sum);
        if (sum < ans)
        {
            ans = sum;
            ansid = index;
        }
    }
    else // 简单旅行商环路
    {
        printf("Path %d: %d (TS simple cycle)\n", index, sum);
        if (sum < ans)
        {
            ans = sum;
            ansid = index;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> city1 >> city2 >> dist;
        rec[city1][city2] = rec[city2][city1] = dist;
    }

    cin >> k;
    for (int i = 1; i <= k; i++)
        check(i);
    printf("Shortest Dist(%d) = %d\n", ansid, ans);
    return 0;
}