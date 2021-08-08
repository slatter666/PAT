#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k, n;
    double a;
    double rec[1005] = {0};
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf(" %d %lf", &n, &a);
            rec[n] += a;
        }
    }

    vector<pair<int, double>> vec;
    for (int i = 1000; i >= 0; i--)
    {
        if (rec[i] != 0)
            vec.push_back(pair<int, double>(i, rec[i]));
    }

    printf("%d", vec.size());
    for (int i = 0; i < vec.size(); i++)
        printf(" %d %.1lf", vec[i].first, vec[i].second);
    return 0;
}

// 采用map实现
// #include <iostream>
// #include <map>
// using namespace std;

// map<int, double, greater<int>> rec;

// int main()
// {
//     int k, n;
//     double an;
//     for (int i = 0; i < 2; i++)
//     {
//         cin >> k;
//         for (int j = 0; j < k; j++)
//         {
//             cin >> n >> an;
//             rec[n] += an;
//             if (rec[n] == 0) // 如果系数为0需要删掉，此处细节很重要
//                 rec.erase(rec.find(n));
//         }
//     }

//     cout << rec.size();
//     map<int, double>::iterator it;
//     for (it = rec.begin(); it != rec.end(); it++)
//         printf(" %d %.1f", it->first, it->second);
//     cout << endl;
//     return 0;
// }