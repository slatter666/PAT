#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct node
{
    int N, A;
};
int n, k, m;
vector<node> ans;

bool isPrime(int x)
{
    if (x <= 3)
        return x >= 3; // 这题特殊要求，不能是2
    else if (x % 6 != 1 && x % 6 != 5)
        return false;

    int sq = sqrt(x);
    for (int i = 5; i < sq; i += 6)
    {
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    }
    return true;
}

int gcd(int x, int y)
{
    int temp = y;
    while (y != 0)
    {
        y = x % y;
        x = temp;
        temp = y;
    }
    return x;
}

int calculate(int x)
{
    int result = 0;
    while (x > 0)
    {
        result += x % 10;
        x /= 10;
    }
    return result;
}

void dfs(int x, int sum, int restK)
{
    if (restK == 0)
    {
        if (sum == m)
        {
            int tempN = calculate(x + 1);
            if (isPrime(gcd(tempN, m)))
                ans.push_back({tempN, x});
        }
    }
    else if (restK > 0)
    {
        for (int i = 0; i <= 9; i++)
        {
            if (sum + i + (restK - 1) * 9 >= m && sum + i <= m) // 下一位取i
                dfs(x * 10 + i, sum + i, restK - 1);
        }
    }
}

bool cmp(node n1, node n2)
{
    if (n1.N != n2.N)
        return n1.N < n2.N;
    else
        return n1.A < n2.A;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k >> m;
        printf("Case %d\n", i);

        ans.clear();
        for (int i = 1; i <= 9; i++)
            dfs(i, i, k - 1);

        if (ans.size() == 0)
            printf("No Solution\n");
        else
        {
            sort(ans.begin(), ans.end(), cmp);
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i].N << " " << ans[i].A << endl;
        }
    }
    return 0;
}