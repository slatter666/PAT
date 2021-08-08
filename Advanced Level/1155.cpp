#include <iostream>
#include <vector>
using namespace std;

int n, maxTag = 1, minTag = 1;
int tree[1005];
vector<int> vec;

void dfs(int root)
{
    if (root * 2 > n)
    {
        if (root <= n)
        {
            for (int i = 0; i < vec.size(); i++)
            {
                cout << vec[i];
                if (i != vec.size() - 1)
                    cout << " ";
                else
                    cout << endl;
            }
        }
    }
    else
    {
        vec.push_back(tree[root * 2 + 1]);
        dfs(root * 2 + 1);
        vec.pop_back();
        vec.push_back(tree[root * 2]);
        dfs(root * 2);
        vec.pop_back();
    }
}

int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> tree[i];

    vec.push_back(tree[1]);
    dfs(1);

    for (int i = 2; i <= n; i++)
    {
        if (tree[i] > tree[i / 2]) // 大于父结点则不可能是大顶堆
            maxTag = 0;
        if (tree[i] < tree[i / 2]) // 小于父结点则不可能是小顶堆
            minTag = 0;
    }

    if (maxTag == 1)
        cout << "Max Heap" << endl;
    else if (minTag == 1)
        cout << "Min Heap" << endl;
    else
        cout << "Not Heap" << endl;
}