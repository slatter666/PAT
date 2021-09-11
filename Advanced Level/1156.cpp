#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x)
{
    if (x <= 1)
        return false;
    else if (x == 2 || x == 3)
        return true;
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

int main()
{
    int n;
    cin >> n;
    if (isPrime(n))
    {
        if (isPrime(n - 6))
        {
            cout << "Yes" << endl;
            cout << n - 6 << endl;
            return 0;
        }
        else if (isPrime(n + 6))
        {
            cout << "Yes" << endl;
            cout << n + 6 << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    while (true)
    {
        n++;
        if (isPrime(n) && (isPrime(n - 6) || isPrime(n + 6)))
        {
            cout << n << endl;
            return 0;
        }
    }

    return 0;
}