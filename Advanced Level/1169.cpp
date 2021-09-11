#include <iostream>
#include <vector>
#include <map>
using namespace std;

int num1, num2, n, m;
int game[15][1005];
bool check[100005], winner[15];
vector<int> rec;
map<int, bool> exist;

int main()
{
    cin >> num1 >> num2;
    rec.push_back(num1);
    rec.push_back(num2);
    check[abs(num1 - num2)] = true;

    exist[num1] = true, exist[num2] = true;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        winner[i] = true;
        for (int j = 1; j <= m; j++)
            cin >> game[i][j];
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (winner[j] == false)
                continue;

            int cur = game[j][i];
            if (check[cur] == true && exist[cur] == false)
            {
                exist[cur] = true;
                for (int k = 0; k < rec.size(); k++)
                    check[abs(cur - rec[k])] = true;
                rec.push_back(cur);
            }
            else
            {
                printf("Round #%d: %d is out.\n", i, j);
                winner[j] = false;
            }
        }
    }

    vector<int> win;
    for (int i = 1; i <= n; i++)
        if (winner[i] == true)
            win.push_back(i);

    if (win.size() == 0)
        printf("No winner.\n");
    else
    {
        printf("Winner(s):");
        for (int i = 0; i < win.size(); i++)
            printf(" %d", win[i]);
    }
    return 0;
}