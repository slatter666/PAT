#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int m, n, u, v;
    cin >> m >> n;
    map<int, bool> exist;
    vector<int> pre(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
        exist[pre[i]] = true;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        if (exist[u] == true && exist[v] == true)
        {
            int res;
            for (int j = 0; j < n; j++)
            {
                res = pre[j];
                if (res == u || res == v || (res < u && res > v) || (res < v && res > u))
                    break;
            }
            if (res == u)
                printf("%d is an ancestor of %d.\n", u, v);
            else if (res == v)
                printf("%d is an ancestor of %d.\n", v, u);
            else
                printf("LCA of %d and %d is %d.\n", u, v, res);
        }
        else if (exist[u] == false && exist[v] == false)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (exist[u] == false && exist[v] == true)
            printf("ERROR: %d is not found.\n", u);
        else if (exist[u] == true && exist[v] == false)
            printf("ERROR: %d is not found.\n", v);
    }
    return 0;
}