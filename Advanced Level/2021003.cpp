#include <iostream>
using namespace std;

const int MAXN = 50005;
int n, pos = 0;
int pre[MAXN], in[MAXN], post[MAXN];

void getPre(int root, int left, int right)
{
    if (left > right)
        return;
    int i = left;
    while (i < right && in[i] != post[root])
        i++;
    pre[pos++] = post[root];
    getPre(root - (right - i + 1), left, i - 1);
    getPre(root - 1, i + 1, right);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> post[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    getPre(n - 1, 0, n - 1);
    cout << pre[n - 1] << endl;
    return 0;
}