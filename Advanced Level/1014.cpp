#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct window
{
    int poptime = 0;
    int endtime = 0;
    queue<int> q;
};

int main()
{
    int n, m, k, q, index = 1;
    cin >> n >> m >> k >> q;
    vector<int> time(k + 1), result(k + 1);
    for (int i = 1; i <= k; i++)
    {
        cin >> time[i];
    }

    vector<window> serve(n + 1);
    vector<bool> sorry(k + 1, false);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (index <= k)
            {
                serve[j].q.push(time[index]);
                if (serve[j].endtime >= 540)
                    sorry[index] = true;
                serve[j].endtime += time[index];

                if (i == 1)
                    serve[j].poptime = serve[j].endtime;
                result[index] = serve[j].endtime;
                index++;
            }
        }
    }

    while (index <= k)
    {
        int tempmin = serve[1].poptime, tempwindow = 1;
        for (int i = 2; i <= n; i++)
        {
            if (serve[i].poptime < tempmin)
            {
                tempwindow = i;
                tempmin = serve[i].poptime;
            }
        }
        serve[tempwindow].q.pop();
        serve[tempwindow].q.push(time[index]);
        serve[tempwindow].poptime += serve[tempwindow].q.front();
        if (serve[tempwindow].endtime >= 540)
            sorry[index] = true;
        serve[tempwindow].endtime += time[index];
        result[index] = serve[tempwindow].endtime;
        index++;
    }

    for (int i = 1; i <= q; i++)
    {
        int query;
        cin >> query;
        if (sorry[query] == true)
            cout << "Sorry" << endl;
        else
            printf("%02d:%02d\n", (480 + result[query]) / 60, (480 + result[query]) % 60);
    }
    return 0;
}