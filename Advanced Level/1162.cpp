#include <iostream>
using namespace std;

struct node
{
    string data;
    int left, right;
} tree[25];

int n, root = 1;
bool check[25];

string dfs(int index)
{
    if (index == -1)
        return "";
    if (tree[index].left == -1 && tree[index].right != -1)
        tree[index].data = "(" + tree[index].data + dfs(tree[index].right) + ")";
    else
        tree[index].data = "(" + dfs(tree[index].left) + dfs(tree[index].right) + tree[index].data + ")";
    return tree[index].data;
}

int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i].data >> tree[i].left >> tree[i].right;
        if (tree[i].left != -1)
            check[tree[i].left] = true;
        if (tree[i].right != -1)
            check[tree[i].right] = true;
    }

    while (check[root])
        root++;
    cout << dfs(root) << endl;
    return 0;
}