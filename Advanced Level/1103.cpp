#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, k, p, maxFacSum = -1;
vector<int> rec, ans, tempAns;

void init()
{
    int temp = 0, index = 1;
    while (temp <= n)
    {
        rec.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}

void dfs(int index, int tempSum, int tempK, int facSum)
{
    if (tempK == k)
    {
        if (tempSum == n && facSum > maxFacSum)
        {
            ans = tempAns;
            maxFacSum = facSum;
        }
        return;
    }
    while (index >= 1)
    {
        if (tempSum + rec[index] <= n)
        {
            tempAns[tempK] = index;
            dfs(index, tempSum + rec[index], tempK + 1, facSum + index);
        }
        if (index == 1)
            return; // 1是最后一个了，不可能继续下去了
        index--;
    }
}

int main()
{
    cin >> n >> k >> p;
    init();
    tempAns.resize(k);
    dfs(rec.size() - 1, 0, 0, 0);
    if (maxFacSum == -1)
        cout << "Impossible" << endl;
    else
    {
        printf("%d = ", n);
        for (int i = 0; i < ans.size(); i++)
        {
            if (i != 0)
                printf(" + ");
            printf("%d^%d", ans[i], p);
        }
    }
    return 0;
}