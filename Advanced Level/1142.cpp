#include <iostream>
#include <vector>
using namespace std;

bool edge[205][205];

int main()
{
    int nv, ne, v1, v2, m, k;
    cin >> nv >> ne;
    for (int i = 0; i < ne; i++)
    {
        cin >> v1 >> v2;
        edge[v1][v2] = edge[v2][v1] = true;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        vector<int> rec(k);
        for (int i = 0; i < k; i++)
            cin >> rec[i];

        bool flag1 = true;
        for (int j = 0; j < k && flag1; j++)
            for (int s = 0; s < k && flag1; s++)
                if (j != s && edge[rec[j]][rec[s]] == false)
                    flag1 = false;

        if (!flag1)
            cout << "Not a Clique" << endl;
        else
        {
            bool flag2 = true;
            for (int j = 1; j <= nv; j++)
            {
                for (int s = 0; s < k; s++)
                {
                    if (edge[j][rec[s]] == false)
                        break;
                    if (s == k - 1)
                        flag2 = false;
                }
                if (flag2 == false)
                {
                    cout << "Not Maximal" << endl;
                    break;
                }
            }
            if (flag2)
                cout << "Yes" << endl;
        }
    }
    return 0;
}