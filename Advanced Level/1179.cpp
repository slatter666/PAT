#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int M = 100 + 2;
int n, m, k;
vector<int> reacts(M, 0);
vector<int> products;
unordered_map<int, vector<vector<int>>> mp;
vector<int> visited(M, 0);
vector<int> tmp;
vector<int> ans;
bool ok = false;
void dfs(int t)
{
    if (ok)
        return;
    if (t == m)
    {
        ans = tmp;
        ok = true;
        return;
    }
    int x = products[t];
    for (int i = 0; i < mp[x].size(); i++)
    {
        tmp.push_back(i);
        bool ok = true;
        int j = 0;
        for (; j < mp[x][i].size(); j++)
        {
            if (visited[mp[x][i][j]])
            {
                ok = false;
                break;
            }
            visited[mp[x][i][j]] = 1;
        }
        if (!ok)
        {
            for (int u = 0; u < j; u++)
                visited[mp[x][i][u]] = 0;
            tmp.pop_back();
            continue;
        }
        dfs(t + 1);
        
        for (j = 0; j < mp[x][i].size(); j++)         // 我没搞懂这三行的用处，但是确实需要写
            visited[mp[x][i][j]] = 0;
        tmp.pop_back();
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        reacts[x] = 1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        products.push_back(x);
        if (reacts[x] == 0)
            continue;
        vector<int> tmp = {x};
        mp[x].push_back(tmp);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        vector<int> tmp;
        string s;
        bool ok = true;
        while (true)
        {
            cin >> s;
            if (s == "->")
                break;
            if (isdigit(s[0]))
            {
                int t = atoi(s.c_str());
                if (reacts[t] == 0)
                    ok = false;
                tmp.push_back(t);
            }
        }
        int t;
        scanf("%d", &t);
        if (ok)
            mp[t].push_back(tmp);
    }
    for (auto a : products)
        sort(mp[a].begin(), mp[a].end());

    dfs(0);

    for (int i = 0; i < m; i++)
    {
        int t = ans[i];
        bool first = true;
        auto v = mp[products[i]][t];
        for (auto a : v)
        {
            if (first)
                first = false;
            else
                printf(" + ");
            printf("%02d", a);
        }
        printf(" -> %02d\n", products[i]);
    }
}