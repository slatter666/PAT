#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool check[100000];
int n, m, good1, good2;
map<int, vector<int>> rec;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> good1 >> good2;
        rec[good1].push_back(good2);
        rec[good2].push_back(good1);
    }

    for (int i = 0; i < m; i++)
    {
        fill(check, check + 100000, false);
        bool flag = true;
        int k, good;
        cin >> k;
        vector<int> temp(k);
        for (int j = 0; j < k; j++)
            cin >> temp[j];
        for (int j = 0; j < k; j++)
        {
            if (check[temp[j]] == true)
            {
                flag = false;
                break;
            }
            for (int s = 0; s < rec[temp[j]].size(); s++)
                check[rec[temp[j]][s]] = true;
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}