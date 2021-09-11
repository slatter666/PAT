#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n, p, len = 1;
    int sequence[100005];
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> sequence[i];

    sort(sequence, sequence + n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + len; j < n; j++)
        {
            if (sequence[j] <= sequence[i] * p)
                len = j - i + 1;
            else
                break;
        }
    }
    cout << len << endl;
    return 0;
}