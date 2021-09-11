#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

const int MAXN = 1005;
int n, m, k;
int S[MAXN][MAXN], D[MAXN][MAXN];
unordered_map<int, vector<int>> grid; // 记录拓扑图
vector<int> pre, minS, maxD;
vector<int> preCnt; // 记录入度

int main()
{
    fill(S[0], S[0] + MAXN * MAXN, -1);
    fill(D[0], D[0] + MAXN * MAXN, -1);
    cin >> n >> m;
    pre.resize(n, -1); // -1意味着还没处理
    minS.resize(n, 1e9);
    maxD.resize(n, 0);
    preCnt.resize(n, 0);

    for (int i = 0; i < m; i++)
    {
        int t1, t2, s, d;
        cin >> t1 >> t2 >> s >> d;
        S[t1][t2] = s;
        D[t1][t2] = d;
        grid[t1].push_back(t2);
        preCnt[t2]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (preCnt[i] == 0)
        {
            q.push(i);
            minS[i] = 0;
            maxD[i] = 0;
            pre[i] = i;
        }
    }

    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        if (grid[t].size() == 0)
            continue;
        for (auto x : grid[t])
        {
            int s = minS[t], d = maxD[t];
            if (s + S[t][x] < minS[x] || (s + S[t][x] == minS[x] && d + D[t][x] > maxD[x]))
            {
                pre[x] = t;
                minS[x] = s + S[t][x];
                maxD[x] = d + D[t][x];
            }
            preCnt[x]--;
            if (preCnt[x] == 0)
                q.push(x);
        }
    }

    bool ok = true;
    for (int i = 0; i < n; i++)
        if (pre[i] == -1) // 如果有点没被处理，那么一定存在环，只有环才会导致一个点入度始终不为0
            ok = false;

    if (ok)
        printf("Okay.\n");
    else
        printf("Impossible.\n");

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int id;
        cin >> id;
        if (pre[id] == -1) // 少打个等号
            printf("Error.\n");
        else if (pre[id] == id)
            printf("You may take test %d directly.\n", id);
        else
        {
            vector<int> rec;
            while (true)
            {
                rec.push_back(id);
                if (id == pre[id])
                    break;
                id = pre[id];
            }

            for (int j = rec.size() - 1; j >= 0; j--) // j++ 写成了 j--
            {
                if (j != rec.size() - 1)
                    printf("->");
                printf("%d", rec[j]);
            }
            printf("\n");
        }
    }
    return 0;
}