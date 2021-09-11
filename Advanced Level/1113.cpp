#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, n1, result = 0;
    cin >> n;
    vector<int> rec(n);
    for (int i = 0; i < n; i++)
        cin >> rec[i];

    sort(rec.begin(), rec.end(), greater<int>());
    n1 = n % 2 == 0 ? n / 2 : n / 2 + 1;
    for (int i = 0; i < n; i++)
    {
        if (i < n1)
            result += rec[i];
        else
            result -= rec[i];
    }
    cout << 2 * n1 - n << " " << result << endl;
    return 0;
}