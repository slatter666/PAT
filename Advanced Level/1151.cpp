#include <iostream>
#include <map>
using namespace std;

int pre[10005], in[10005];
map<int, int> pos;

void lca(int left, int right, int preRoot, int u, int v)
{
    if (left > right)
        return;
    int inRoot = pos[pre[preRoot]], uIn = pos[u], vIn = pos[v]; // 当前根节点在中序遍历中的位置，u、v分别在中序遍历中的位置
    if (uIn < inRoot && vIn < inRoot)
        lca(left, inRoot - 1, preRoot + 1, u, v);
    else if ((uIn < inRoot && vIn > inRoot) || (uIn > inRoot && vIn < inRoot))
        printf("LCA of %d and %d is %d.\n", u, v, in[inRoot]);
    else if (uIn > inRoot && vIn > inRoot)
        lca(inRoot + 1, right, preRoot + 1 + inRoot - left, u, v); //
    else if (uIn == inRoot)
        printf("%d is an ancestor of %d.\n", u, v); // u就是该子树根结点
    else if (vIn == inRoot)
        printf("%d is an ancestor of %d.\n", v, u); // v就是该子树根结点
}

int main()
{
    int m, n, u, v;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> in[i];
        pos[in[i]] = i;
    }

    for (int i = 1; i <= n; i++)
        cin >> pre[i];

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        if (pos[u] == 0 && pos[v] == 0)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (pos[u] == 0)
            printf("ERROR: %d is not found.\n", u);
        else if (pos[v] == 0)
            printf("ERROR: %d is not found.\n", v);
        else
            lca(1, n, 1, u, v);
    }
}