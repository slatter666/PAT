#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int begin, end;
} rec[300];

bool cmp(node n1, node n2)
{
    return n1.end < n2.end;
}

int main()
{
    int n;
    int h1, m1, s1;
    int h2, m2, s2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        rec[i] = {h1 * 3600 + m1 * 60 + s1, h2 * 3600 + m2 * 60 + s2};
    }
    sort(rec, rec + n, cmp);
    int cnt = 1, prev = rec[0].end;
    for (int i = 1; i < n; i++)
    {
        if (rec[i].begin >= prev)
        {
            prev = rec[i].end;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}