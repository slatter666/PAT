#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 105, INF = 0x3f3f3f3f;
vector<vector<int>> edge(MAXN);
int rec[MAXN];
bool visit[MAXN];

int maxTotal;

void dfs(int start, int total)
{
    if (start == INF)
        return;
    if (total > maxTotal)
        maxTotal = total;
    visit[start] = true;
    int minNum = INF;
    for (int i = 0; i < edge[start].size(); i++) // 之前在那儿无脑找，后面看题意只需要找最小那个数字就行了
    {
        int next = edge[start][i];
        if (visit[next] == false && next < minNum)
            minNum = next;
    }
    dfs(minNum, total + 1);
}

int main()
{
    int n, m, v1, v2;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }

    for (int i = 1; i <= n; i++)
    {
        fill(visit, visit + MAXN, false);
        maxTotal = 0;
        dfs(i, 1);
        rec[i] = maxTotal;
    }

    int maxSpot = 0, resIndex;
    for (int i = 1; i <= n; i++)
    {
        if (rec[i] > maxSpot)
        {
            resIndex = i;
            maxSpot = rec[i];
        }
    }
    cout << resIndex << " " << maxSpot; // 这题输出spot不包含自身
    return 0;
}