#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph(1005);
bool visited[1005];
int lost;

void dfs(int occupy)
{
    visited[occupy] = true;
    for (int i = 0; i < graph[occupy].size(); i++)
    {
        if (!visited[graph[occupy][i]] && graph[occupy][i] != lost)
            dfs(graph[occupy][i]);
    }
}

int main()
{
    int n, m, k, begin, end;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> begin >> end;
        graph[begin].push_back(end);
        graph[end].push_back(begin);
    }

    for (int i = 0; i < k; i++)
    {
        cin >> lost;
        fill(visited, visited + 1005, 0);
        int count = 0;
        for (int j = 1; j <= n; j++)
        {
            if (j == lost)
                continue;
            else if (!visited[j])
            {
                dfs(j);
                count++;
            }
        }
        cout << count - 1 << endl;
    }
    return 0;
}