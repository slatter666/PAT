#include <iostream>
#include <vector>
using namespace std;

int start[10005];
int size[10005];
vector<int> rec;

int main()
{
    int n, k, query, maxQuery = -1;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> start[i] >> size[i];
        for (int j = 0; j < size[i]; j++)
            rec.push_back(start[i] + j * 4);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> query;
        if (query >= rec.size())
            cout << "Illegal Access" << endl;
        else
        {
            maxQuery = max(maxQuery, query);
            cout << rec[query] << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (maxQuery < size[i])
        {
            cout << i + 1 << endl;
            break;
        }
        else
            maxQuery -= size[i];
    }
    return 0;
}

// #include <iostream>
// using namespace std;

// struct node
// {
//     int initial, len;
// } arr[10005];
// bool visit[10005];

// int main()
// {
//     int n, k, query, total = 0, maxNum = 0;
//     cin >> n >> k;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i].initial >> arr[i].len;
//         total += arr[i].len;
//     }

//     for (int i = 0; i < k; i++)
//     {
//         cin >> query;
//         if (query >= total)
//             cout << "Illegal Access" << endl;
//         else
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 maxNum = max(j + 1, maxNum);
//                 if (arr[j].len <= query)
//                     query -= arr[j].len;
//                 else
//                 {
//                     cout << arr[j].initial + query * 4 << endl;
//                     break;
//                 }
//             }
//         }
//     }
//     cout << maxNum << endl;
//     return 0;
// }

// 这个代码主要是如果直接越界就输出1，因为从一开始是有一个数组的，而不是所有的都是临时建的，如果觉得这个更好理解请自行修改