#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1005, INF = 0x3f3f3f3f;
int nv, ne, v1, v2, w, k;
int edge[MAXN][MAXN];
int dist[MAXN];
bool visit[MAXN];

int main()
{
    fill(edge[0], edge[0] + MAXN * MAXN, INF); // 开始忘写了，一直没找到错误原因
    cin >> nv >> ne;
    for (int i = 0; i < ne; i++)
    {
        cin >> v1 >> v2 >> w;
        edge[v1][v2] = edge[v2][v1] = w;
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        bool flag = true;
        fill(dist, dist + MAXN, INF);
        fill(visit, visit + MAXN, false);
        vector<int> sequence(nv + 1);
        for (int j = 1; j <= nv; j++)
            cin >> sequence[j];

        dist[sequence[1]] = 0;
        for (int j = 1; j <= nv; j++)
        {
            int v = sequence[j];
            for (int s = 1; s <= nv; s++)
                if (visit[s] == false && dist[s] < dist[v]) // 当前存在比该结点更短的结点
                    flag = false;

            if (flag == false)
                break;
            visit[v] = true;
            for (int s = 1; s <= nv; s++)
            {
                if (dist[s] > dist[v] + edge[v][s])
                    dist[s] = dist[v] + edge[v][s];
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}