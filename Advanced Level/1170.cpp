#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct node
{
    int v1, v2;
};

const int MAXN = 505;
int n, r, k, r1, r2, m;
vector<node> relation;

int main()
{
    cin >> n >> r >> k;
    for (int i = 0; i < r; i++)
    {
        cin >> r1 >> r2;
        relation.push_back({r1, r2});
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        bool flag = true;
        vector<int> rec(n + 1);
        set<int> check;
        for (int j = 1; j <= n; j++)
        {
            cin >> rec[j];
            check.insert(rec[j]);
        }

        for (int j = 0; j < r; j++)
        {
            if (rec[relation[j].v1] == rec[relation[j].v2])
            {
                flag = false;
                break;
            }
        }
        if (check.size() > k)
            printf("Error: Too many species.\n");
        else if (check.size() < k)
            printf("Error: Too few species.\n");
        else if (check.size() == k && flag == true)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}