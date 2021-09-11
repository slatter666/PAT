#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 205, INF = 0x3f3f3f3f;
int n, m, s1, s2, d;
int edge[MAXN][MAXN];
bool visit[MAXN];

void froyd()
{
    for (int k = 0; k <= n; k++)
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                if (edge[i][j] > edge[i][k] + edge[k][j])
                    edge[i][j] = edge[i][k] + edge[k][j];
}

int main()
{
    fill(edge[0], edge[0] + MAXN * MAXN, INF);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s1 >> s2 >> d;
        edge[s1][s2] = edge[s2][s1] = d;
    }
    froyd();
    printf("0");
    bool flag = true;
    visit[0] = true;
    int cur = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        int next = -1, min_dist = INF;
        for (int j = 0; j <= n; j++)
        {
            if (visit[j] == false && (next == -1 || edge[cur][j] < edge[cur][next]))
                next = j;
        }
        if (edge[cur][next] == INF)
        {
            flag = false;
            break;
        }

        printf(" %d", next);
        visit[next] = true;
        sum += edge[cur][next];
        cur = next;
    }
    printf("\n");
    if (flag)
        printf("%d\n", sum);
    else
    {
        int cnt = 0;
        for (int i = 0; i <= n; i++)
        {
            if (visit[i] == false)
            {
                if (cnt != 0)
                    printf(" ", i);
                printf("%d", i);
                cnt++;
            }
        }
    }
    return 0;
}