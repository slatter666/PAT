#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAX = 205, INF = 0x3f3f3f3f;
int n, k, cost;
string start, city1, city2;
int route[MAX][MAX];
bool visit[MAX];
int happiness[MAX], dist[MAX], pre[MAX], num[MAX], total[MAX], len[MAX]; //dist是dijskra数组, pre用于路径回溯,num记录最短路径条数,total记录总幸福度, len记录当前路径逻辑长度，比如a->b->c，那么c逻辑长度为2
map<string, int> stringToInt;
map<int, string> intToString;
vector<string> path;

void dijkstra()
{
    dist[0] = 0;
    total[0] = 0;
    len[0] = 0;
    num[0] = 1;
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
            if (dist[v] + route[v][j] == dist[j])
            {
                num[j] += num[v];
                if (total[j] < total[v] + happiness[j]) // 路径长度相同，选择幸福感更高的一条路径
                {
                    total[j] = total[v] + happiness[j];
                    len[j] = len[v] + 1;
                    pre[j] = v;
                }
                else if (total[j] == total[v] + happiness[j]) // 路径长度相同，幸福感相同，选择平均幸福感更高的一条路径
                {
                    if (len[v] + 1 < len[j]) // 数字越大，平均下来就越小嘛，不用去算平均
                    {
                        len[j] = len[v] + 1;
                        pre[j] = v;
                    }
                }
            }
            else if (dist[v] + route[v][j] < dist[j]) // 路径长度不同，选择路径长度更短的一条路径
            {
                num[j] = num[v];
                len[j] = len[v] + 1;
                dist[j] = dist[v] + route[v][j];
                total[j] = total[v] + happiness[j];
                pre[j] = v;
            }
        }
    }
}

void dfs(int city)
{
    if (city == 0)
    {
        path.push_back(intToString[city]);
        return;
    }
    dfs(pre[city]);
    path.push_back(intToString[city]);
}

int main()
{
    fill(dist, dist + MAX, INF);
    fill(route[0], route[0] + MAX * MAX, INF);
    cin >> n >> k >> start;
    stringToInt[start] = 0;
    intToString[0] = start;
    for (int i = 1; i < n; i++)
    {
        cin >> city1 >> happiness[i];
        stringToInt[city1] = i;
        intToString[i] = city1;
    }

    for (int i = 0; i < k; i++)
    {
        cin >> city1 >> city2 >> cost;
        int c1 = stringToInt[city1], c2 = stringToInt[city2];
        route[c1][c2] = route[c2][c1] = cost;
    }

    dijkstra();
    int rome = stringToInt["ROM"];
    dfs(rome);
    cout << num[rome] << " " << dist[rome] << " " << total[rome] << " " << total[rome] / len[rome] << endl;
    for (int i = 0; i < path.size(); i++)
    {
        if (i != 0)
            cout << "->";
        cout << path[i];
    }
    return 0;
}