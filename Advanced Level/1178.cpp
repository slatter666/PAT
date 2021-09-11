#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, k, query;
    string cur;
    int prev[10000];
    fill(prev, prev + 10000, -1);
    vector<int> rec[10005];
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, cur);
        int num = stoi(cur);
        int len = cur.size() - 4; // len的数值代表第len级目录
        if (len == 0)
            prev[num] = num;
        else
            prev[num] = rec[len - 1].back();
        rec[len].push_back(num);
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> query;
        bool flag = true;
        vector<int> path;
        while (flag)
        {
            path.push_back(query);
            if (query == prev[query])
                break;
            else if (prev[query] == -1)
            {
                flag = false;
                break;
            }
            query = prev[query];
        }

        if (flag)
        {
            for (int i = path.size() - 1; i >= 0; i--)
            {
                if (i != path.size() - 1)
                    printf("->");
                printf("%04d", path[i]);
            }
            printf("\n");
        }
        else
            printf("Error: %04d is not found.\n", query);
    }
    return 0;
}