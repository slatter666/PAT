#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;
int m, n;
int tree[MAX];

void postOrder(int root)
{
    if (root > n)
        return;
    postOrder(2 * root);
    postOrder(2 * root + 1);
    if (root == 1)
        cout << tree[root] << endl;
    else
        cout << tree[root] << " ";
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        bool isMaxHeap = true, isMinHeap = true;
        for (int j = 1; j <= n; j++)
            cin >> tree[j];

        for (int j = 2; j <= n; j++)
        {
            if (tree[j] > tree[j / 2]) //小顶堆
                isMaxHeap = 0;
            if (tree[j] < tree[j / 2]) // 大顶堆
                isMinHeap = 0;
        }
        if (!isMaxHeap && !isMinHeap)
            cout << "Not Heap" << endl;
        else if (isMaxHeap)
            cout << "Max Heap" << endl;
        else if (isMinHeap)
            cout << "Min Heap" << endl;
        postOrder(1);
    }
    return 0;
}