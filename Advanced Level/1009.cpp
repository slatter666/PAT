#include <iostream>
using namespace std;
int main()
{
    int n1, n2, a, cnt = 0;
    scanf("%d", &n1);
    double b, arr[1001] = {0.0}, ans[2001] = {0.0};
    for (int i = 0; i < n1; i++)
    {
        scanf("%d %lf", &a, &b);
        arr[a] = b;
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d %lf", &a, &b);
        for (int j = 0; j < 1001; j++)
            ans[j + a] += arr[j] * b;
    }
    for (int i = 2000; i >= 0; i--)
        if (ans[i] != 0.0)
            cnt++;
    printf("%d", cnt);
    for (int i = 2000; i >= 0; i--)
        if (ans[i] != 0.0)
            printf(" %d %.1f", i, ans[i]);
    return 0;
}

// 采用map实现
// #include <iostream>
// #include <map>
// using namespace std;

// map<int, double, greater<int>> rec, res;

// int main()
// {
//     int k, n;
//     double an;
//     cin >> k;
//     for (int i = 0; i < k; i++)
//     {
//         cin >> n >> an;
//         rec[n] = an;
//     }
//     map<int, double>::iterator it;
//     cin >> k;
//     for (int i = 0; i < k; i++)
//     {
//         cin >> n >> an;
//         for (it = rec.begin(); it != rec.end(); it++)
//         {
//             res[it->first + n] += it->second * an;
//             if (res[it->first + n] == 0) // 此处细节依然不能遗漏
//                 res.erase(res.find(it->first + n));
//         }
//     }

//     cout << res.size();
//     for (it = res.begin(); it != res.end(); it++)
//         printf(" %d %.1f", it->first, it->second);
//     return 0;
// }