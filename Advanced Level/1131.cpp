#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> v(10000);
int start, dest, minCnt, minTransfer;
int visit[10000];
unordered_map<int, int> line;
vector<int> path, tempPath;

int transferCnt(vector<int> t)
{
    int cnt = -1, preLine = 0;
    for (int i = 1; i < t.size(); i++)
    {
        if (line[t[i - 1] * 10000 + t[i]] != preLine)
            cnt++;
        preLine = line[t[i - 1] * 10000 + t[i]];
    }
    return cnt;
}

void dfs(int node, int cnt)
{
    if (node == dest && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer)))
    {
        minCnt = cnt;
        minTransfer = transferCnt(tempPath);
        path = tempPath;
    }

    if (node == dest)
        return;
    for (int i = 0; i < v[node].size(); i++)
    {
        if (visit[v[node][i]] == 0)
        {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], cnt + 1);
            visit[v[node][i]] = 0;
            tempPath.pop_back();
        }
    }
}

int main()
{
    int n, m, k, pre, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> pre;
        for (int j = 1; j < m; j++)
        {
            cin >> temp;
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre * 10000 + temp] = line[temp * 10000 + pre] = i + 1; // pre * 10000 + temp实际上是实现一个拼接操作，比如pre=1001 temp=3212，那么拼接之后就是10013212，后续操作更方便
            pre = temp;
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> start >> dest;
        minCnt = 99999, minTransfer = 99999;
        tempPath.clear();
        tempPath.push_back(start);
        visit[start] = 1;
        dfs(start, 0);
        visit[start] = 0;
        cout << minCnt << endl;
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < path.size(); j++)
        {
            if (line[path[j - 1] * 10000 + path[j]] != preLine)
            {
                if (preLine != 0)
                    printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j - 1]);
                preLine = line[path[j - 1] * 10000 + path[j]];
                preTransfer = path[j - 1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, dest);
    }

    return 0;
}