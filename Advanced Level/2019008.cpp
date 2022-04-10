#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1015;
int ns, na, m, k, call, total; // ns求救点数目,na救助站数目,m条公路,total表示总的地点数目 total = ns + na
int cars[15];
int cost[MAXN][MAXN], streets[MAXN][MAXN], pre[MAXN][MAXN], dist[MAXN][MAXN]; // cost记录路径之间时间花销,streets用于记录到达求救点要经过多少条路,pre用于路径回溯
bool visit[MAXN];
bool traversal[MAXN]; // 对于每个点只dijskra一次，避免重复遍历花费时间

bool dijskra()
{
    bool flag = false;
    for (int i = 1; i <= na; i++)
    {
        if (cars[i] != 0)
            flag = true;
    }
    if (flag == false)
        return false; // 无车
    if (traversal[call])
        return true;

    fill(visit, visit + MAXN, false);
    dist[call][call] = 0;
    for (int i = 1; i <= total; i++)
    {
        int v = -1;
        for (int j = 1; j <= total; j++)
        {
            if (visit[j] == false && (v == -1 || dist[call][j] < dist[call][v]))
                v = j;
        }

        visit[v] = true;
        for (int j = 1; j <= total; j++)
        {
            if (visit[j] == false)
            {
                if (dist[call][v] + cost[v][j] < dist[call][j])
                {
                    dist[call][j] = dist[call][v] + cost[v][j];
                    streets[call][j] = streets[call][v] + 1; // 记录路径条数
                    pre[call][j] = v;
                }
                else if (dist[call][v] + cost[v][j] == dist[call][j] && streets[call][v] + 1 < streets[call][j])
                {
                    streets[call][j] = streets[call][v] + 1;
                    pre[call][j] = v;
                }
            }
        }
    }
    traversal[call] = true;
    return flag; // 有车
}

void storePath()
{
    string s1, s2;
    int v1, v2, time;
    cin >> s1 >> s2 >> time;
    if (s1[0] == 'A')
        v1 = stoi(s1.substr(2)) + ns;
    else
        v1 = stoi(s1);
    if (s2[0] == 'A')
        v2 = stoi(s2.substr(2)) + ns;
    else
        v2 = stoi(s2);
    cost[v1][v2] = cost[v2][v1] = time;
}

int main()
{
    fill(cost[0], cost[0] + MAXN * MAXN, INF);
    fill(dist[0], dist[0] + MAXN * MAXN, INF);
    fill(streets[0], streets[0] + MAXN * MAXN, 0);
    string s1, s2;
    int v1, v2;
    cin >> ns >> na;
    total = ns + na;
    for (int i = 1; i <= na; i++)
        cin >> cars[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        storePath();
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> call;
        if (dijskra() == false)
            cout << "All Busy" << endl;
        else
        {

            int minTime = INF, ambulance = -1;
            for (int i = ns + 1; i <= total; i++)
            {
                if (dist[call][i] < minTime && cars[i - ns] > 0) // 首先找花费时间最小的，这里i-ns少些个ns调试了半天
                {
                    minTime = dist[call][i];
                    ambulance = i;
                }
                else if (dist[call][i] == minTime)
                {
                    if (cars[i - ns] > cars[ambulance - ns]) // 花费时间相同，找有最多车辆的救助站，艹了这里也搞忘加ns了
                        ambulance = i;
                    else if (cars[i - ns] == cars[ambulance - ns] && streets[call][i - ns] < streets[call][ambulance - ns]) // 花费时间也相同，找走的公路条数最少的，妈的这里也没加ns，我是傻逼
                        ambulance = i;
                }
            }
            cars[ambulance - ns]--; // 每次派发都要减去一辆车，这里也要减ns
            int next = ambulance;
            while (true)
            {
                if (next != call)
                {
                    if (next > ns) // 救助站需要加"A-"
                        cout << "A-" << next - ns << " ";
                    else
                        cout << next << " ";
                    next = pre[call][next];
                }
                else
                {
                    cout << next << endl;
                    cout << minTime << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

// 别人的AC代码,我上面代码只有26分
// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = 1020, INF = 0x3fffffff;
// int ns, na, cars[20], G[maxn][maxn], d[20][maxn];
// bool vis[maxn];
// struct node
// {
//     int id, d;
//     bool operator<(const node &tmp) const { return d > tmp.d; }
// };
// vector<int> pre[20][maxn]; //求解出每个医院到pick_up的前驱数组
// void Dijkstra(int start)
// {
//     int H = start - ns;
//     memset(vis, false, sizeof(vis));
//     fill(d[H], d[H] + maxn, INF);
//     d[H][start] = 0;
//     priority_queue<node> pq;
//     pq.push(node{start, 0});
//     while (!pq.empty())
//     {
//         node now = pq.top();
//         pq.pop();
//         if (vis[now.id])
//             continue;
//         vis[now.id] = true;
//         for (int i = 1; i <= na + ns; ++i)
//         {
//             if (vis[i] == false && G[now.id][i] != 0)
//             {
//                 if (now.d + G[now.id][i] < d[H][i])
//                 {
//                     d[H][i] = now.d + G[now.id][i];
//                     pre[H][i].clear();
//                     pre[H][i].push_back(now.id);
//                     pq.push(node{i, d[H][i]});
//                 }
//                 else if (now.d + G[now.id][i] == d[H][i])
//                 {
//                     pre[H][i].push_back(now.id);
//                     pq.push(node{i, d[H][i]});
//                 }
//             }
//         }
//     }
// }
// vector<int> tmp, ans;
// void DFS(int id, int hos, int &min_edge)
// {
//     if (tmp.size() > min_edge)
//         return;
//     tmp.push_back(id);
//     if (id == hos)
//     {
//         if (tmp.size() - 1 <= min_edge) // WRONG 1: 最短路径不唯一：要选择编号大的一条（第二条）
//         {
//             min_edge = tmp.size() - 1;
//             ans = tmp;
//         }
//         tmp.pop_back();
//         return;
//     }
//     for (auto nex : pre[hos - ns][id])
//     {
//         DFS(nex, hos, min_edge);
//     }
//     tmp.pop_back();
// }

// int Change(char s[]);
// void Print(const vector<int> &v);
// int main()
// {
//     scanf("%d %d", &ns, &na);
//     for (int i = 1; i <= na; ++i)
//     {
//         scanf("%d", &cars[i]);
//     }
//     int m;
//     scanf("%d", &m);
//     for (int i = 0; i < m; ++i)
//     {
//         int tmp_cost;
//         char tmp[2][10];
//         scanf("%s %s %d", tmp[0], tmp[1], &tmp_cost);
//         int v1 = Change(tmp[0]), v2 = Change(tmp[1]);
//         G[v1][v2] = G[v2][v1] = tmp_cost;
//     }
//     for (int i = 1; i <= na; ++i)
//     {
//         Dijkstra(i + ns);
//     }
//     int nq;
//     scanf("%d", &nq);
//     for (int i = 0; i < nq; ++i)
//     {
//         int pick_up, MIN_LEN = INF, MAX_CARS = -1, MIN_EDGE = INF;
//         scanf("%d", &pick_up);
//         vector<int> res;
//         for (int j = 1; j <= na; ++j)
//         {
//             // d[j][pick_up] == 医院j到p的最短距离
//             if (cars[j] > 0)
//             {
//                 int min_streets = INF;
//                 DFS(pick_up, j + ns, min_streets);
//                 if (d[j][pick_up] < MIN_LEN)
//                 {
//                     MIN_LEN = d[j][pick_up];
//                     MAX_CARS = cars[j];
//                     MIN_EDGE = min_streets;
//                     res = ans;
//                 }
//                 else if (d[j][pick_up] == MIN_LEN)
//                 {
//                     if (cars[j] > MAX_CARS)
//                     {
//                         MAX_CARS = cars[j];
//                         MIN_EDGE = min_streets;
//                         res = ans;
//                     }
//                     else if (cars[j] == MAX_CARS && min_streets < MIN_EDGE)
//                     {
//                         MIN_EDGE = min_streets;
//                         res = ans;
//                     }
//                 }
//             }
//         }
//         if (res.size() == 0)
//         {
//             printf("All Busy\n");
//         }
//         else
//         {
//             Print(res);
//             printf("%d\n", MIN_LEN);
//             cars[res[res.size() - 1] - ns]--;
//         }
//         res.clear();
//     }
//     return 0;
// }

// int Change(char s[])
// {
//     return s[0] == 'A' ? atoi(strcpy(s, s + 2)) + ns : atoi(s);
// }
// void Print(const vector<int> &ans)
// {
//     for (int i = ans.size() - 1; i >= 0; --i)
//     {
//         if (ans[i] > ns)
//             printf("A-%d", ans[i] - ns);
//         else
//             printf("%d", ans[i]);
//         if (i > 0)
//             printf(" ");
//         else
//             printf("\n");
//     }
// }