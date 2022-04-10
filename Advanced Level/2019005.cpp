#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(long long int n)
{
    if (n <= 3)
        return n > 1;
    else if (n % 6 != 1 && n % 6 != 5)
        return false;

    int sq = sqrt(n);
    for (long long int i = 5; i <= sq; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    long long int n;
    string result;
    vector<int> rec;
    cin >> n;
    if (n == 1) // 有个测试点是1
    {
        cout << 1 << endl;
        cout << "No" << endl;
    }
    else
    {
        while (n != 1)
        {
            for (int i = 2; i <= n; i++)
            {
                if (n % i == 0)
                {
                    rec.push_back(i);
                    n /= i;
                    break;
                }
            }
        }
        result += to_string(rec[0]);
        int cnt = 1;
        for (int i = 1; i < rec.size(); i++)
        {
            if (rec[i] == rec[i - 1])
                cnt++;
            else
            {
                if (cnt > 1)
                    result += to_string(cnt);
                result += to_string(rec[i]);
                cnt = 1;
            }
        }
        if (cnt > 1)
            result += to_string(cnt);

        cout << result << endl;
        if (isPrime(stoll(result)))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}