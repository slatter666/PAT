#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k, c1, c2, lost;
bool visit[1005];
vector<vector<int>> graph;

void dfs(int occupy)
{
    visit[occupy] = true;
    for (int i = 0; i < graph[occupy].size(); i++)
    {
        if (graph[occupy][i] != lost && visit[graph[occupy][i]] == false)
            dfs(graph[occupy][i]);
    }
}

int main()
{
    cin >> n >> m >> k;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> c1 >> c2;
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }

    for (int i = 0; i < k; i++)
    {
        cin >> lost;
        int cnt = 0;
        fill(visit, visit + 1005, 0);
        for (int j = 1; j <= n; j++)
        {
            if (visit[j] == false && j != lost) // 计算有多少个连通图，然后cnt减1就是所需要修建的铁路条数
            {
                dfs(j);
                cnt++;
            }
        }
        cout << cnt - 1 << endl;
    }
    return 0;
}