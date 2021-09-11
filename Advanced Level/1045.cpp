#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, l, temp, maxlen = 1;
    int favorite[205] = {0}, dp[10005]; // dp数组要开大一点，因为dp是根据l的大小来设置的
    vector<int> rec;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp;
        favorite[temp] = i; // 用来标识顺序
    }

    cin >> l;
    for (int i = 0; i < l; i++)
    {
        cin >> temp;
        if (favorite[temp] > 0)
            rec.push_back(favorite[temp]);
    }

    for (int i = 0; i < rec.size(); i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (rec[i] >= rec[j])
                dp[i] = max(dp[i], dp[j] + 1);
        maxlen = max(maxlen, dp[i]);
    }
    cout << maxlen << endl;
    return 0;
}