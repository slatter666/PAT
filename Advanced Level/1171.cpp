#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, m, index = 0, cnt = 0, last;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> next, current;                        // next存放下轮的数，current存放本轮的数
    priority_queue<int, vector<int>, greater<int>> q; // 小顶堆
    for (index = 0; index < m; index++)
        q.push(arr[index]);

    while (cnt != n)
    {
        last = q.top();
        current.push_back(last);
        q.pop();
        cnt++;
        if (index < n)
        {
            if (arr[index] < last) //
                next.push_back(arr[index++]);
            else
                q.push(arr[index++]);
        }

        if (q.empty())
        {
            for (int i = 0; i < current.size(); i++)
            {
                if (i != 0)
                    cout << " ";
                cout << current[i];
            }
            cout << endl;
            current.clear();
            for (int i = 0; i < next.size(); i++)
                q.push(next[i]);
            next.clear();
        }
    }
    return 0;
}