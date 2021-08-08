#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 999999999;
int minNeed = INF, minBack = INF;
int e[505][505], dist[505], weight[505]; //结点之间路径长度、最短路径长度、目前站点车辆数
vector<vector<int>> pre(505);
vector<int> path, temppath;
bool visit[505];

void dfs(int v)
{
    temppath.push_back(v);
    if (v == 0)
    {
        int need = 0, back = 0; //运出、运回
        for (int i = temppath.size() - 1; i >= 0; i--)
        {
            int id = temppath[i];
            if (weight[id] > 0) // 大于完美则带回
            {
                back += weight[id];
            }
            else //小于完美
            {
                if (back > (0 - weight[id])) // 中途拿上的车够用
                    back += weight[id];
                else //中途拿上的车不够用
                {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }

        if (need < minNeed)
        {
            minNeed = need;
            minBack = back;
            path = temppath;
        }
        else if (need == minNeed && back < minBack)
        {
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);

    temppath.pop_back();
}

int main()
{
    fill(e[0], e[0] + 505 * 505, INF);
    fill(dist, dist + 505, INF);
    int cmax, n, sp, m, begin, end, len;
    cin >> cmax >> n >> sp >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
        weight[i] = weight[i] - cmax / 2;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> begin >> end >> len;
        e[begin][end] = len;
        e[end][begin] = len;
    }

    dist[0] = 0;

    // dijkstra
    for (int i = 0; i <= n; i++)
    {
        int u = -1, minn = INF;
        for (int j = 0; j <= n; j++)
        {
            if (visit[j] == false && dist[j] < minn)
            {

                u = j;
                minn = dist[j];
            }
        }
        if (u == -1)
            break;

        visit[u] = true;
        for (int k = 0; k <= n; k++)
        {
            if (visit[k] == false && e[u][k] != INF)
            {
                if (dist[k] > dist[u] + e[u][k])
                {
                    dist[k] = dist[u] + e[u][k];
                    pre[k].clear();
                    pre[k].push_back(u);
                }
                else if (dist[k] == dist[u] + e[u][k])
                {
                    pre[k].push_back(u);
                }
            }
        }
    }

    // dfs
    dfs(sp);
    cout << minNeed << " ";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i];
        if (i != 0)
            cout << "->";
    }
    cout << " " << minBack << endl;
    return 0;
}