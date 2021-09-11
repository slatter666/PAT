#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 505, INF = 0x3f3f3f3f;
int cmax, n, sp, m, si, sj, tij;
int minNeed = INF, minBack = INF;
int bikes[MAX], dist[MAX]; //bikes记录当前站点车辆数,dist是dijskra数组
int cost[MAX][MAX];
bool visit[MAX];
vector<int> path, tempPath, pre[MAX]; // 路径,pre记录候选结点

void dijkstra() // 一个dijkstra干完所有事，dfs仅仅用于回溯路径不可行，因为该题不满足最优子结构
{
    dist[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        int v = -1;
        for (int j = 0; j <= n; j++)
            if (visit[j] == false && (v == -1 || dist[j] < dist[v]))
                v = j;

        visit[v] = true;
        for (int j = 0; j <= n; j++)
        {
            if (v == j)
                continue;
            if (dist[v] + cost[v][j] == dist[j])
                pre[j].push_back(v);
            else if (dist[v] + cost[v][j] < dist[j])
            {
                dist[j] = dist[v] + cost[v][j];
                pre[j].clear();
                pre[j].push_back(v);
            }
        }
    }
}

void dfs(int sta)
{
    tempPath.push_back(sta);
    if (sta == 0) // 此时一条待选路径产生，进行判断是否更新path
    {
        int need = 0, back = 0;
        for (int i = tempPath.size() - 1; i >= 0; i--)
        {
            int id = tempPath[i];
            if (bikes[id] > 0)
                back += bikes[id];
            else
            {
                if (back > (0 - bikes[id]))
                    back += bikes[id];
                else
                {
                    need += (0 - bikes[id] - back);
                    back = 0;
                }
            }
        }
        if (need < minNeed)
        {
            minNeed = need;
            minBack = back;
            path = tempPath;
        }
        else if (need == minNeed && back < minBack)
        {
            minBack = back;
            path = tempPath;
        }
    }
    for (int i = 0; i < pre[sta].size(); i++)
        dfs(pre[sta][i]);
    tempPath.pop_back();
}

int main()
{
    fill(dist, dist + MAX, INF);
    fill(cost[0], cost[0] + MAX * MAX, INF);
    cin >> cmax >> n >> sp >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> bikes[i];
        bikes[i] -= cmax / 2;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> si >> sj >> tij;
        cost[si][sj] = cost[sj][si] = tij;
    }
    dijkstra();
    dfs(sp);
    cout << minNeed << " ";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        if (i != path.size() - 1)
            cout << "->";
        cout << path[i];
    }
    cout << " " << minBack << endl;
    return 0;
}