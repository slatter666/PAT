#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, m, k, v1, v2, nv;
    cin >> n >> m;
    vector<int> rec[n];
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        rec[v1].push_back(v2);
        rec[v2].push_back(v1);
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int cnt = 0, nv, num;
        bool flag = true;
        map<int, bool> check;
        cin >> nv;
        for (int j = 0; j < nv; j++)
        {
            cin >> num;
            check[num] = true;
        }

        for (int j = 0; j < n && flag; j++) // 注意这里是n，因为总共n个结点
            for (int s = 0; s < rec[j].size() && flag; s++)
                if (check[j] == false && check[rec[j][s]] == false)
                    flag = false;

        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

// 下面这个应该性能上更优
// #include <iostream>
// #include <vector>
// #include <set>
// using namespace std;

// struct edge
// {
//     int begin, end;
// };
// vector<edge> e;

// int main()
// {
//     int n, m, v1, v2, k, nv;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> v1 >> v2;
//         e.push_back({v1, v2});
//     }

//     cin >> k;
//     for (int i = 0; i < k; i++)
//     {
//         cin >> nv;
//         int temp;
//         bool flag = true;
//         set<int> s;
//         for (int j = 0; j < nv; j++)
//         {
//             cin >> temp;
//             s.insert(temp);
//         }
//         for (int j = 0; j < m; j++)
//         {
//             int start = e[j].begin;
//             int last = e[j].end;
//             if (s.find(start) == s.end() && s.find(last) == s.end())
//             {
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag)
//             cout << "Yes" << endl;
//         else
//             cout << "No" << endl;
//     }
//     return 0;
// }