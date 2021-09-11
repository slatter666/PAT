#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int x)
{
    if (x <= 3)
        return x >= 2;
    else if (x % 6 != 1 && x % 6 != 5)
        return false;

    int sq = sqrt(x);
    for (int i = 5; i <= sq; i += 6)
    {
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, maxp, maxdif;
    cin >> n >> maxp;
    maxdif = (maxp - 2) / (n - 1);
    for (int i = maxdif; i >= 2; i--)
    {
        for (int j = maxp; j >= 2; j--)
        {
            bool flag = true;
            vector<int> rec;
            if (j - (n - 1) * i < 0) // 第一项小于最小素数2
                break;
            if (isPrime(j) == false) // 最大项不为素数
                continue;
            for (int cnt = 0, k = j; cnt < n; k -= i, cnt++)
            {
                rec.push_back(k);
                if (isPrime(k) == false)
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                for (int k = rec.size() - 1; k >= 0; k--)
                {
                    if (k != rec.size() - 1)
                        cout << " ";
                    cout << rec[k];
                }
                cout << endl;
                return 0;
            }
        }
    }

    while (true)
    {
        if (isPrime(maxp))
        {
            cout << maxp << endl;
            break;
        }
        maxp--;
    }
    return 0;
}