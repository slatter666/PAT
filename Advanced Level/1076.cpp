#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node
{
    int id, level; // 结构体主要是需要用来记录层数
};

vector<vector<int>> vec;

void bfs(node root, int level)
{
    int cnt = 0;
    bool visit[1005] = {0};
    queue<node> q;
    q.push(root);
    visit[root.id] = true;
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        int cid = cur.id;
        for (int i = 0; i < vec[cid].size(); i++)
        {
            int nextUser = vec[cid][i];
            if (visit[nextUser] == false && cur.level < level) // 当前level层小于l则下一层小于等于l可以入队
            {
                node next = {nextUser, cur.level + 1};
                q.push(next);
                visit[nextUser] = true; // 这里多打个等号，debug好久
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

int main()
{
    int n, l, m, user, k, query;
    cin >> n >> l;
    vec.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> user;
            vec[user].push_back(i);
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> query;
        node root = {query, 0}; // 自己是在第0层，user[query]中的followers是在第一层
        bfs(root, l);
    }
    return 0;
}