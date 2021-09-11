#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct window
{
    int poptime = 0, endtime = 0;
    queue<int> q;
};

int main()
{
    int n, m, k, query, num, index = 1;
    cin >> n >> m >> k >> query;
    vector<int> proc(k + 1), finish(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> proc[i];

    vector<window> serve(n + 1);
    vector<bool> sorry(k + 1, false);          // 这里不小心将k敲成了n导致最后一个测试点没过
    for (int i = 1; i <= m && index <= k; i++) // m个容量
    {
        for (int j = 1; j <= n && index <= k; j++) // n个窗口
        {
            serve[j].q.push(proc[index]);
            if (serve[j].endtime >= 540)
                sorry[index] = true;
            serve[j].endtime += proc[index];

            if (i == 1)
                serve[j].poptime = proc[index];
            finish[index] = serve[j].endtime;
            index++;
        }
    }

    while (index <= k)
    {
        int tempmin = serve[1].poptime, tempwindow = 1;
        for (int i = 2; i <= n; i++) // 找到最先完成业务的窗口
        {
            if (serve[i].poptime < tempmin)
            {
                tempwindow = i;
                tempmin = serve[i].poptime;
            }
        }

        serve[tempwindow].q.pop();                                // 完成业务离开
        serve[tempwindow].q.push(proc[index]);                    // 下一位进入队列等待
        serve[tempwindow].poptime += serve[tempwindow].q.front(); // 更新下一次业务结束时间
        if (serve[tempwindow].endtime >= 540)
            sorry[index] = true;

        serve[tempwindow].endtime += proc[index];
        finish[index] = serve[tempwindow].endtime;
        index++;
    }

    for (int i = 0; i < query; i++)
    {
        cin >> num;
        if (sorry[num])
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", 8 + finish[num] / 60, finish[num] % 60);
    }
    return 0;
}