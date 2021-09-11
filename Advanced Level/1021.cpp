#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int maxheight = 0;
bool visit[10005];
set<int> result;
vector<int> rec; // 记录所要找的最深根
vector<vector<int>> edge;

void dfs(int node, int height)
{
    if (height > maxheight)
    {
        rec.clear();
        rec.push_back(node);
        maxheight = height;
    }
    else if (height == maxheight)
    {
        rec.push_back(node);
    }
    visit[node] = true;
    for (int i = 0; i < edge[node].size(); i++)
    {
        if (visit[edge[node][i]] == false)
            dfs(edge[node][i], height + 1);
    }
}

int main()
{
    int n, node1, node2, root, cnt = 0; // cnt记录有多少个连通分量
    cin >> n;
    edge.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == false)
        {
            dfs(i, 1);
            if (i == 1)
            {
                root = rec[0]; // 第一轮dfs对于任何一个结点，离该结点越远则肯定是根，存在根的情况下至少有两个根，但第一轮并不一定能统计完全
                for (int j = 0; j < rec.size(); j++)
                    result.insert(rec[j]); // 把得到的根全部存入结果中，用set是可以自动去重，因为存在一些结点第一轮会进入第二轮依然还会进入
            }
            cnt++; // dfs一次找到一个连通分量，加一次cnt
        }
    }

    if (cnt >= 2)
        printf("Error: %d components", cnt);
    else
    {
        rec.clear();
        fill(visit, visit + 10005, false);
        maxheight = 0;
        dfs(root, 1);
        for (int i = 0; i < rec.size(); i++)
            result.insert(rec[i]);
        for (auto it : result)
            cout << it << endl;
    }
    return 0;
}