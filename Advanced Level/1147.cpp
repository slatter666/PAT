#include <iostream>
using namespace std;

int m, n;
int tree[1005];

void postorder(int root)
{
    if (root * 2 <= n)
        postorder(root * 2);
    if (root * 2 + 1 <= n)
        postorder(root * 2 + 1);
    cout << tree[root];
    if (root != 1)
        cout << " ";
    else
        cout << endl;
}

int main()
{
    int maxTag, minTag;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        maxTag = 1, minTag = 1;
        for (int j = 1; j <= n; j++)
            cin >> tree[j];

        for (int k = 2; k <= n; k++)
        {
            if (tree[k] > tree[k / 2]) //小顶堆
                maxTag = 0;
            if (tree[k] < tree[k / 2]) // 大顶堆
                minTag = 0;
        }

        if (maxTag == 1)
            cout << "Max Heap" << endl;
        else if (minTag == 1)
            cout << "Min Heap" << endl;
        else
            cout << "Not Heap" << endl;
        postorder(1);
    }
}