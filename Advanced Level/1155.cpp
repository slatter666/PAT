#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, maxHeap = 1, minHeap = 1;
int tree[1005];
bool printed[1005];
vector<int> path;

void traversal(int index)
{
    if (index > n)
    {
        if (printed[index / 2] == false && index / 2 > n / 2)
        {
            for (int i = 0; i < path.size(); i++)
            {
                if (i != 0)
                    cout << " ";
                cout << path[i];
            }
            cout << endl;
            printed[index / 2] = true;
        }
        return;
    }
    path.push_back(tree[index]);
    if (index != 1)
    {
        if (tree[index] > tree[index / 2]) // 小顶堆
            maxHeap = 0;
        if (tree[index] < tree[index / 2]) // 大顶堆
            minHeap = 0;
    }
    traversal(2 * index + 1);
    traversal(2 * index);
    path.pop_back();
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> tree[i];
    traversal(1);
    if (minHeap == 0 && maxHeap == 0)
        cout << "Not Heap" << endl;
    else if (minHeap == 1)
        cout << "Min Heap" << endl;
    else if (maxHeap == 1)
        cout << "Max Heap" << endl;
    return 0;
}