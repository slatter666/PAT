#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string a, string b)
{
    return a + b < b + a;
}

int main()
{
    int n;
    cin >> n;
    vector<string> rec(n);
    for (int i = 0; i < n; i++)
        cin >> rec[i];

    sort(rec.begin(), rec.end(), cmp);
    string result = "";
    for (int i = 0; i < n; i++)
        result += rec[i];

    while (result[0] == '0')
        result.erase(0, 1);
    // cout << result << endl;      不能放在这里的原因是由于出现 2 000 0这种情况时会出现一个空行，导致格式出问题，测试点二格式错误
    if (result == "")
        cout << 0;
    cout << result << endl;
    return 0;
}