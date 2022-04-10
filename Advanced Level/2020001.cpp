#include <iostream>
using namespace std;

int main()
{
    int n;
    int root[15], temp[15], result[15];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> root[i];
        root[i] = -root[i];
    }

    result[1] = 1; // 第一个因式存入
    result[0] = root[0];

    for (int i = 1; i < n; i++) // n个多项式需要乘n-1次，i指明了当前最高次数
    {
        for (int j = 0; j <= i; j++) // 将前面i个多项式乘积结果保存
            temp[j] = result[j];

        for (int j = i + 1; j > 0; j--) // 先乘x项
            result[j] = result[j - 1];

        result[0] = 0;
        for (int j = 0; j <= i; j++) // 再乘常数项
            result[j] += root[i] * temp[j];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << result[i];
        if (i != 0)
            cout << " ";
    }
    return 0;
}

// DFS实现
// #include <iostream>
// #include <vector>
// using namespace std;

// int n;
// vector<int> root(15), result(15, 0);

// void dfs(int pol, int val, int coe) // pol代表多项式个数，val代表值，coe代表次数，
// {
//     if (pol == n) // n个多项式相乘完毕
//         result[coe] += val;
//     else
//     {
//         dfs(pol + 1, val * root[pol], coe); // 乘以常数项
//         dfs(pol + 1, val, coe + 1);         // 乘以x
//     }
// }

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> root[i];
//         root[i] = -root[i];
//     }
//     dfs(0, 1, 0);

//     for (int i = n - 1; i >= 0; i--)
//     {
//         cout << result[i];
//         if (i != 0)
//             cout << " ";
//     }
//     return 0;
// }