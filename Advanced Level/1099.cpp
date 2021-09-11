#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int cnt;
struct node
{
    int value;
    int left, right;
} tree[120];

int arr[110];

void dfs(int root)
{
    if (tree[root].left != -1)
        dfs(tree[root].left);
    tree[root].value = arr[cnt++];
    if (tree[root].right != -1)
        dfs(tree[root].right);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> tree[i].left >> tree[i].right;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    dfs(0);
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        cout << tree[head].value;
        if (tree[head].left != -1)
            q.push(tree[head].left);
        if (tree[head].right != -1)
            q.push(tree[head].right);
        if (!q.empty())
            cout << " ";
    }
    cout << endl;
    return 0;
}