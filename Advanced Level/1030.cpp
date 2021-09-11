#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 505, INF = 0x3f3f3f3f;
int n, m, s, d, city1, city2, len, cst;
int dist[MAX], total[MAX], pre[MAX]; //dist是dijskra数组, total是到其他地方所需最小花费, pre记录路径
int highway[MAX][MAX], cost[MAX][MAX];
bool visit[MAX];
vector<int> path; // 路径

void dijkstra()
{
    dist[s] = 0;
    total[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (visit[j] == false && (v == -1 || dist[j] < dist[v])) // 这里少打个等号，debug至少15分钟，难受
                v = j;

        visit[v] = true;
        for (int j = 0; j < n; j++)
        {
            if (j == v) // 这个不写也没什么关系，写了看起来逻辑更清晰而已
                continue;
            if (dist[v] + highway[v][j] == dist[j])
            {
                if (total[v] + cost[v][j] < total[j])
                {
                    total[j] = total[v] + cost[v][j];
                    pre[j] = v;
                }
            }
            else if (dist[v] + highway[v][j] < dist[j])
            {
                dist[j] = dist[v] + highway[v][j];
                total[j] = total[v] + cost[v][j];
                pre[j] = v;
            }
        }
    }
}

void dfs(int city)
{
    if (city == s)
    {
        path.push_back(s);
        return;
    }
    dfs(pre[city]);
    path.push_back(city);
}

int main()
{
    cin >> n >> m >> s >> d;
    fill(dist, dist + MAX, INF);
    fill(highway[0], highway[0] + MAX * MAX, INF);

    for (int i = 0; i < m; i++)
    {
        cin >> city1 >> city2 >> len >> cst;
        highway[city1][city2] = highway[city2][city1] = len;
        cost[city1][city2] = cost[city2][city1] = cst;
    }
    dijkstra();
    dfs(d);
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    cout << dist[d] << " " << total[d] << endl;
    return 0;
}