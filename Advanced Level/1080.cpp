#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct student
{
    int id, ge, gi, final;
    vector<int> prefer;
};

bool cmp1(student s1, student s2)
{
    return s1.final != s2.final ? s1.final > s2.final : s1.ge > s2.ge;
}

bool cmp2(student s1, student s2)
{
    return s1.id < s2.id;
}

int main()
{
    int n, m, k;
    int quota[105];
    cin >> n >> m >> k;
    vector<student> stu(n), school[m];
    for (int i = 0; i < m; i++)
        cin >> quota[i];

    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].ge >> stu[i].gi;
        stu[i].id = i;
        stu[i].final = stu[i].ge + stu[i].gi;
        stu[i].prefer.resize(k);
        for (int j = 0; j < k; j++)
            cin >> stu[i].prefer[j];
    }

    sort(stu.begin(), stu.end(), cmp1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int pid = stu[i].prefer[j]; // 意向学校
            if (school[pid].size() < quota[pid] || (stu[i].final == school[pid].back().final && stu[i].ge == school[pid].back().ge))
            {
                school[pid].push_back(stu[i]);
                break;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        sort(school[i].begin(), school[i].end(), cmp2);
        for (int j = 0; j < school[i].size(); j++)
        {
            if (j != 0)
                cout << " ";
            cout << school[i][j].id;
        }
        cout << endl;
    }
    return 0;
}