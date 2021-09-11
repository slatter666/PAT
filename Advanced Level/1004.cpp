#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, k, id, idx;
    scanf("%d %d", &n, &m);
    vector<vector<int>> tree(n + 1);
    vector<vector<int>> level(n);
    level[0].push_back(1);
    int l[n + 1] = {0};
    l[1] = 0;
    for (int i = 0; i < m; i++)      //由于存在数据并不是顺序读入的情况，所以先读入tree数组中
    {
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &idx);
            tree[id].push_back(idx);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < tree[i].size(); j++)
        {
            l[tree[i][j]] = l[i] + 1;
            level[l[tree[i][j]]].push_back(tree[i][j]);
        }
    }

    vector<int> rec;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        if (level[i].size() == 0)
            break;
        else
        {
            for (int j = 0; j < level[i].size(); j++)
            {
                int node = level[i][j];
                if (tree[node].size() == 0)
                    count++;
            }
            rec.push_back(count);
        }
    }

    for (int i = 0; i < rec.size(); i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", rec[i]);
    }
    return 0;
}