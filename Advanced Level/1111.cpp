#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 505, INF = 0x3f3f3f3f;
int n, m, v1, v2, isOne, len, t, source, dest; // 题目中one-way其实就是指单行道，如果值为0就是双向道
int street[MAX][MAX], cost[MAX][MAX];
bool visit[MAX];
int dist[MAX], time[MAX], preDist[MAX], preTime[MAX], recTime[MAX], recSec[MAX]; //dist和time都是dijskra数组, preDist用于最短路径回溯,preTime用于最短用时回溯,recTime记录距离相同时选择用时更短的路,recSec记录用时相同时选择经过路口最少的路
vector<int> distPath, timePath;                                                  // 最短路径、最快路径

void dijkstraDist() // 最短路径dijkstra
{
    dist[source] = 0;
    recTime[source] = 0;
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (visit[j] == false && (v == -1 || dist[j] < dist[v]))
                v = j;

        visit[v] = true;
        for (int j = 0; j < n; j++)
        {
            if (j == v)
                continue;
            if (dist[v] + street[v][j] == dist[j] && (recTime[v] + cost[v][j] < recTime[j]))
            {
                recTime[j] = recTime[v] + cost[v][j];
                preDist[j] = v;
            }
            else if (dist[v] + street[v][j] < dist[j])
            {
                dist[j] = dist[v] + street[v][j];
                recTime[j] = recTime[v] + cost[v][j];
                preDist[j] = v;
            }
        }
    }
}

void dijkstraTime() // 最快路径dijkstra
{
    time[source] = 0; // 还是建议重写的好，直接复制粘贴再修改这里搞忘改成time运行直接中途中断了
    recSec[source] = 0;
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (visit[j] == false && (v == -1 || time[j] < time[v]))
                v = j;

        visit[v] = true;
        for (int j = 0; j < n; j++)
        {
            if (j == v)
                continue;
            if (time[v] + cost[v][j] == time[j] && (recSec[v] + 1 < recSec[j]))
            {
                recSec[j] = recSec[v] + 1;
                preTime[j] = v;
            }
            else if (time[v] + cost[v][j] < time[j])
            {
                time[j] = time[v] + cost[v][j];
                recSec[j] = recSec[v] + 1;
                preTime[j] = v;
            }
        }
    }
}

void dfsDistPath(int loc)
{
    if (loc == source)
    {
        distPath.push_back(loc);
        return;
    }
    dfsDistPath(preDist[loc]);
    distPath.push_back(loc);
}

void dfsTimePath(int loc)
{
    if (loc == source)
    {
        timePath.push_back(loc);
        return;
    }
    dfsTimePath(preTime[loc]);
    timePath.push_back(loc);
}

int main()
{
    fill(dist, dist + MAX, INF);
    fill(time, time + MAX, INF);
    fill(street[0], street[0] + MAX * MAX, INF);
    fill(cost[0], cost[0] + MAX * MAX, INF);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> isOne >> len >> t;
        street[v1][v2] = len;
        cost[v1][v2] = t;
        if (isOne == 0)
        {
            street[v2][v1] = len;
            cost[v2][v1] = t;
        }
    }

    cin >> source >> dest;
    dijkstraDist();
    dfsDistPath(dest);
    fill(visit, visit + MAX, false);
    dijkstraTime();
    dfsTimePath(dest);

    printf("Distance = %d", dist[dest]);
    if (distPath == timePath) // 两个vector内部元素完全一致的话会返回true,尝试了一下发现实可以采用这种比较的
        printf("; Time = %d: ", time[dest]);
    else
    {
        printf(": ");
        for (int i = 0; i < distPath.size(); i++)
        {
            if (i != 0)
                printf(" -> ");
            printf("%d", distPath[i]);
        }
        printf("\nTime = %d: ", time[dest]);
    }
    for (int i = 0; i < timePath.size(); i++)
    {
        if (i != 0)
            printf(" -> ");
        printf("%d", timePath[i]);
    }
    return 0;
}