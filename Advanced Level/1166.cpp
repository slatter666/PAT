#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 205;
int n, m, v1, v2, k, l, cnt;
bool edge[MAXN][MAXN];
vector<int> relation[MAXN], rec(MAXN);
bool visit[MAXN];

void dfs(int head)
{
    bool flag = true;
    for (int i = 0; i < l; i++)
    {
        if (rec[i] == head)
            continue;
        if (edge[head][rec[i]] == false)
        {
            flag = false;
            break;
        }
    }

    if (flag == false)
        return;
    else
    {
        cnt++;
        visit[head] = true;
        for (int i = 0; i < relation[head].size(); i++)
        {
            int cur = relation[head][i];
            if (visit[cur] == false)
                dfs(cur);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        edge[v1][v2] = edge[v2][v1] = true;
        relation[v1].push_back(v2);
        relation[v2].push_back(v1);
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> l;
        for (int j = 0; j < l; j++)
            cin >> rec[j];

        cnt = 0;
        fill(visit, visit + MAXN, false);
        dfs(rec[0]);
        int tempCnt = 0;
        for (int j = 0; j < l; j++)
        {
            if (visit[rec[j]] == true)
            {
                tempCnt++;
                visit[rec[j]] = false; // 因为之后会查找可以加入的人
            }
        }

        if (tempCnt == l)
        {
            if (cnt == l)
                printf("Area %d is OK.\n", i);
            else if (cnt > l)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (visit[j] == true)
                    {
                        printf("Area %d may invite more people, such as %d.\n", i, j);
                        break;
                    }
                }
            }
        }
        else
            printf("Area %d needs help.\n", i);
    }
    return 0;
}