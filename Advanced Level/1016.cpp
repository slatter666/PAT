#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int rate[25];

struct node
{
    string name;
    int status, month, day, hour, minute, time;
};

bool cmp(node n1, node n2)
{
    if (n1.name != n2.name)
        return n1.name < n2.name;
    else
        return n1.time < n2.time;
}

double calculate(node n1)
{
    double total = rate[n1.hour + 1] * n1.minute + rate[0] * (n1.day - 1); // 还有可能跨天
    for (int i = 1; i <= n1.hour; i++)
        total += rate[i] * 60;
    return total / 100;
}

int main()
{
    int n;
    string temp;
    for (int i = 1; i <= 24; i++)
    {
        cin >> rate[i];
        rate[0] += rate[i] * 60; // 计算出一天打满的    总费用
    }
    cin >> n;
    vector<node> rec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> rec[i].name;
        scanf("%d:%d:%d:%d", &rec[i].month, &rec[i].day, &rec[i].hour, &rec[i].minute);
        cin >> temp;
        if (temp == "on-line")
            rec[i].status = 1;
        else
            rec[i].status = 0;
        rec[i].time = rec[i].day * 24 * 60 + rec[i].hour * 60 + rec[i].minute;
    }

    sort(rec.begin(), rec.end(), cmp);
    map<string, vector<node>> result;
    for (int i = 1; i < n; i++)
    {
        if (rec[i].name == rec[i - 1].name && rec[i].status == 0 && rec[i - 1].status == 1)
        {
            result[rec[i].name].push_back(rec[i - 1]);
            result[rec[i].name].push_back(rec[i]);
        }
    }

    for (auto it : result)
    {
        vector<node> temp = it.second;
        double total = 0;
        printf("%s %02d\n", it.first.c_str(), temp[0].month);
        for (int i = 1; i < temp.size(); i += 2) // 一个用户有多条记录，两两配对
        {
            double price = calculate(temp[i]) - calculate(temp[i - 1]);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, price);
            total += price;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}