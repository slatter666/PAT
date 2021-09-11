#include <iostream>
#include <vector>
using namespace std;

int cnt = 0; // 判断是否为连通图
bool visit[505];
vector<vector<int>> vertice;

void dfs(int cur)
{
    visit[cur] = true;
    cnt++;
    for (int i = 0; i < vertice[cur].size(); i++)
        if (visit[vertice[cur][i]] == false) // 当前未遍历过则遍历
            dfs(vertice[cur][i]);
}

int main()
{
    int n, m, v1, v2, even = 0;
    cin >> n >> m;
    vertice.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        vertice[v1].push_back(v2);
        vertice[v2].push_back(v1);
    }

    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
            cout << " ";
        cout << vertice[i].size();
        if (vertice[i].size() % 2 == 0)
            even++;
    }
    cout << endl;

    dfs(1);
    if (cnt == n && even == n)
        cout << "Eulerian" << endl;
    else if (cnt == n && even == n - 2)
        cout << "Semi-Eulerian" << endl;
    else
        cout << "Non-Eulerian" << endl;
    return 0;
}