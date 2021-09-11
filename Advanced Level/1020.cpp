#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Node
{
    int value = INF;
    int left;
    int right;
} tree[10000];

int in[50], post[50]; // 中序遍历、后序遍历

int pos;
// n为当前子树根节点,l为左子树根节点,r为右子树根节点
void create(int l, int r, int n)
{
    if (l >= r)
        return;

    int root = post[--pos];
    tree[n].value = root;
    tree[n].left = 2 * n;
    tree[n].right = 2 * n + 1;
    int f = find(in, in + r, root) - in;
    create(f + 1, r, 2 * n + 1);
    create(l, f, 2 * n);
}

int main()
{
    int n, count = 0, i = 1;
    cin >> n;
    pos = n;
    for (int i = 0; i < n; i++)
        cin >> post[i];

    for (int i = 0; i < n; i++)
        cin >> in[i];

    create(0, n, 1);
    while (true)
    {
        if (tree[i].value != INF)
        {
            count++;
            cout << tree[i].value;
            if (count != n)
                cout << " ";
            else
                break;
        }
        i++;
    }
    return 0;
}