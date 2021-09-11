#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1015, INF = 0x3f3f3f3f;
int n, m, k, ds, len;
int road[MAX][MAX];
bool visit[MAX];
int dist[MAX]; //dist是dijskra数组

void dijkstra()
{
    int ansId = -1;
    double ansDist = -1, ansAverage = INF;
    for (int loc = n + 1; loc <= n + m; loc++) // 一共m个location候选站
    {
        fill(dist, dist + MAX, INF);
        fill(visit, visit + MAX, false);
        dist[loc] = 0;
        for (int i = 1; i <= n + m; i++) // dijkstra
        {
            int v = -1;
            for (int j = 1; j <= n + m; j++)
                if (visit[j] == false && (v == -1 || dist[j] < dist[v]))
                    v = j;

            visit[v] = true;
            for (int j = 1; j <= n + m; j++)
            {
                if (j == v)
                    continue;
                if (dist[v] + road[v][j] < dist[j])
                    dist[j] = dist[v] + road[v][j];
            }
        }

        double mindist = INF, average = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] > ds)
            {
                mindist = -1; // 至少存在一个点不可达
                break;
            }
            if (dist[i] < mindist)
                mindist = dist[i];
            average += dist[i];
        }

        if (mindist == -1)
            continue;
        else // 类似写sort的cmp函数
        {
            average = average / n;
            if (mindist > ansDist) // 离居民区最近的住宅的距离达到最大
            {
                ansId = loc;
                ansDist = mindist;
                ansAverage = average;
            }
            else if (mindist == ansDist && average < ansAverage)
            {
                ansId = loc;
                ansAverage = average;
            }
            // 本来就是从小到大遍历的，所以最后一个索引最小的要求就不需要判断修改管了
        }
    }
    if (ansId == -1)
        printf("No Solution\n");
    else
        printf("G%d\n%.1f %.1f\n", ansId - n, ansDist, ansAverage);
}

int main()
{
    string p1, p2;
    fill(road[0], road[0] + MAX * MAX, INF);
    cin >> n >> m >> k >> ds;
    for (int i = 0; i < k; i++)
    {
        cin >> p1 >> p2 >> len;
        int t1, t2;
        if (p1[0] == 'G')
            t1 = n + stoi(p1.substr(1));
        else
            t1 = stoi(p1);

        if (p2[0] == 'G')
            t2 = n + stoi(p2.substr(1));
        else
            t2 = stoi(p2);
        road[t1][t2] = road[t2][t1] = len;
    }
    dijkstra();
    return 0;
}