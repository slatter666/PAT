#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct customer
{
    int come;
    int process;
} rec[10005];

bool cmp(customer c1, customer c2)
{
    return c1.come < c2.come;
}

int main()
{
    int n, k, h, m, s, p, cnt = 0, wait = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        int time = h * 60 * 60 + m * 60 + s; // 全部换算为以秒为单位
        if (time > 17 * 60 * 60)
            continue;
        rec[++cnt].come = time;
        rec[cnt].process = p * 60;
    }

    sort(rec + 1, rec + 1 + cnt, cmp);
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= k; i++)
        q.push(28800);
    for (int i = 1; i <= cnt; i++)
    {
        if (q.top() <= rec[i].come) // 不需要等
        {
            q.push(rec[i].come + rec[i].process);
            q.pop();
        }
        else
        {
            wait += q.top() - rec[i].come;
            q.push(q.top() + rec[i].process);
            q.pop();
        }
    }

    printf("%.1f", wait / 60.0 / cnt); // 人数不会为0，当然加上判断也挺好
    return 0;
}


// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <algorithm>
// using namespace std;

// struct node
// {
//     int come, process;
// };

// bool cmp(node n1, node n2)
// {
//     return n1.come < n2.come;
// }

// int main()
// {
//     // 此题是17:00:00之前的（包括17:00:00）都会得到处理
//     int index = 0;
//     int n, k;
//     int h, m, s, pro;
//     cin >> n >> k;
//     node customer[n];
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d:%d:%d %d", &h, &m, &s, &pro);
//         int time = h * 60 * 60 + m * 60 + s;
//         if (time > 17 * 60 * 60)
//             continue;
//         customer[index].come = time - 8 * 60 * 60;
//         customer[index++].process = pro * 60;
//     }

//     sort(customer, customer + index, cmp);
//     int count = 0;
//     double wait = 0;
//     int window[k] = {0};
//     for (int i = 0; i < index; i++)
//     {
//         int temp = 0;
//         for (int j = 1; j < k; j++)
//         {
//             if (window[j] < window[temp])
//             {
//                 temp = j;
//             }
//         }

//         if (window[temp] > customer[count].come)         // 需要等待才会加等待时间，不需要等待则不加
//             wait += window[temp] - customer[count].come; //等待时间

//         window[temp] = max(customer[count].come, window[temp]) + customer[count++].process; // 更新窗口结束时间
//     }

//     printf("%.01f\n", wait / (60 * index));
//     return 0;
// }