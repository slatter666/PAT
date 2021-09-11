#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1005;
int k, n, m, caller, receiver, duration;
int call[MAXN][MAXN];
vector<int> suspect, gang;
bool check[1005] = {0};

void dfs(int index)
{
    check[suspect[index]] = true;
    gang.push_back(suspect[index]);
    for (int i = 0; i < suspect.size(); i++)
        if (check[suspect[i]] == false && call[suspect[index]][suspect[i]] > 0 && call[suspect[i]][suspect[index]] > 0)
            dfs(i);
}

int main()
{
    cin >> k >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> caller >> receiver >> duration;
        call[caller][receiver] += duration;
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0, back = 0;
        for (int j = 1; j <= n; j++)
        {
            if (call[i][j] > 0 && call[i][j] <= 5)
            {
                cnt++;
                if (call[j][i] > 0)
                    back++;
            }
        }
        if (cnt > k && back * 5 <= cnt)
            suspect.push_back(i); // 找到所有嫌疑人
    }

    if (suspect.size() == 0)
        cout << "None" << endl;
    else
    {
        sort(suspect.begin(), suspect.end());
        for (int i = 0; i < suspect.size(); i++)
        {
            if (check[suspect[i]] == false)
            {
                gang.clear();
                dfs(i);
                sort(gang.begin(), gang.end());
                for (int j = 0; j < gang.size(); j++)
                {
                    if (j != 0)
                        cout << " ";
                    cout << gang[j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}