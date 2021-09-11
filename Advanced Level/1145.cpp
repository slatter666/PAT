#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    if (num == 2 || num == 3)
        return true;
    else if (num % 6 != 1 && num % 6 != 5)
        return false;

    int sq = sqrt(num);
    for (int i = 5; i < sq; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    return true;
}

int main()
{
    int msize, n, m, key;
    cin >> msize >> n >> m;
    while (isPrime(msize) == false)
        msize++;

    vector<int> table(msize, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        bool flag = false;
        for (int j = 0; j <= msize; j++)
        {
            int index = (key + j * j) % msize;
            if (table[index] == 0)
            {
                table[index] = key;
                flag = true;
                break;
            }
        }
        if (!flag)
            printf("%d cannot be inserted.\n", key);
    }

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> key;
        for (int j = 0; j <= msize; j++)
        {
            cnt++;
            int index = (key + j * j) % msize;
            if (table[index] == key || table[index] == 0)
                break;
        }
    }
    printf("%.1f\n", cnt * 1.0 / m);
    return 0;
}