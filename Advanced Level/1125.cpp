#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> rec(n);
    for (int i = 0; i < n; i++)
        cin >> rec[i];
    sort(rec.begin(), rec.end());
    int len = rec[0];
    for (int i = 1; i < n; i++)
        len = (len + rec[i]) / 2;
    cout << len << endl;
    return 0;
}