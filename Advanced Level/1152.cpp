#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int t)
{
    if (t <= 3)
        return t > 1;
    else if (t % 6 != 1 && t % 6 != 5)
        return false;

    int sq = sqrt(t);
    for (int i = 5; i < sq; i += 6)
    {
        if (t % i == 0 || t % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    int l, k;
    string str, ans;
    bool flag = false;
    cin >> l >> k >> str;
    for (int i = 0; i <= l - k; i++)
    {
        ans = str.substr(i, k);
        if (isPrime(stoi(ans)))
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << ans << endl;
    else
        cout << 404 << endl;
    return 0;
}