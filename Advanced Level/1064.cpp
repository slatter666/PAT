#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int rec[1005], cbt[1005], in[1005];
int n, pos;

void inorder(int num)
{
    if (num > n)
        return;
    inorder(num * 2);
    in[++pos] = num;
    inorder(num * 2 + 1);
}

int main()
{
    pos = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> rec[i];

    sort(rec + 1, rec + n + 1);
    inorder(1);
    for (int i = 1; i <= n; i++)
        cbt[in[i]] = rec[i];

    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
            cout << " ";
        cout << cbt[i];
    }
    return 0;
}