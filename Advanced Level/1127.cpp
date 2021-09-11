#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int pos, maxDepth = -1;
int in[35], post[35];
vector<int> tree(100000, -1), rec[35];

void create(int l, int r, int cur)
{
    if (l >= r)
        return;
    else
    {
        int root = post[--pos];
        tree[cur] = root;
        int f = find(in, in + r, root) - in;
        create(f + 1, r, 2 * cur + 1);
        create(l, f, 2 * cur);
    }
}

void dfs(int root, int depth)
{
    if (depth > maxDepth)
        maxDepth = depth;
    rec[depth].push_back(tree[root]);
    if (tree[root * 2] != -1)
        dfs(2 * root, depth + 1);
    if (tree[root * 2 + 1] != -1)
        dfs(2 * root + 1, depth + 1);
}

int main()
{
    int n;
    cin >> n;
    pos = n;
    for (int i = 0; i < n; i++)
        cin >> in[i];

    for (int i = 0; i < n; i++)
        cin >> post[i];

    create(0, n, 1);
    dfs(1, 0);
    bool flag = true;
    for (int i = 0; i <= maxDepth; i++)
    {
        if (flag)
        {
            for (int j = rec[i].size() - 1; j >= 0; j--)
            {
                cout << rec[i][j];
                if (i != maxDepth)
                    cout << " ";
                else
                {
                    if (j != 0)
                        cout << " ";
                }
            }
            flag = false;
        }
        else
        {
            for (int j = 0; j <= rec[i].size() - 1; j++)
            {
                cout << rec[i][j];
                if (i != maxDepth)
                    cout << " ";
                else
                {
                    if (j != rec[i].size() - 1)
                        cout << " ";
                }
            }
            flag = true;
        }
    }
    return 0;
}