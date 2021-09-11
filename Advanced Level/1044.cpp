#include <iostream>
using namespace std;

int main()
{
    int n, m, left = 0, minCost = 0x3f3f3f3f; // left表示开始的最低位，minCost用于记录不存在等值时的最小值
    int diamonds[100005] = {0};
    bool notFound = true;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> diamonds[i];
        diamonds[i] += diamonds[i - 1];
        while (diamonds[i] - diamonds[left] > m)
        {
            minCost = min(minCost, diamonds[i] - diamonds[left]);
            left++;
        }
        if (diamonds[i] - diamonds[left] == m)
        {
            cout << left + 1 << "-" << i << endl;
            notFound = false;
        }
    }
    if (notFound)
    {
        left = 0; // 从头开始找等于minCost的
        for (int i = 1; i <= n; i++)
        {
            while (diamonds[i] - diamonds[left] > minCost)
                left++;
            if (diamonds[i] - diamonds[left] == minCost)
                cout << left + 1 << "-" << i << endl;
        }
    }
    return 0;
}