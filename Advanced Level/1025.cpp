#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    string number;
    int grade;
    int final_rank;
    int location;
    int local_rank;
};

bool cmp(node n1, node n2)
{
    return n1.grade != n2.grade ? n1.grade > n2.grade : n1.number < n2.number;
}

int main()
{
    int n, k;
    cin >> n;
    vector<node> stu;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        vector<node> rec(k);
        for (int j = 0; j < k; j++)
        {
            rec[j].location = i;
            cin >> rec[j].number >> rec[j].grade;
        }
        sort(rec.begin(), rec.end(), cmp); // 局部排序
        rec[0].local_rank = 1;
        stu.push_back(rec[0]);
        for (int j = 1; j < k; j++)
        {
            rec[j].local_rank = j + 1;
            if (rec[j].grade == rec[j - 1].grade)
                rec[j].local_rank = rec[j - 1].local_rank;
            stu.push_back(rec[j]);
        }
    }

    sort(stu.begin(), stu.end(), cmp); // 全局排序
    stu[0].final_rank = 1;
    for (int i = 1; i < stu.size(); i++)
    {
        stu[i].final_rank = i + 1;
        if (stu[i].grade == stu[i - 1].grade)
            stu[i].final_rank = stu[i - 1].final_rank;
    }
    cout << stu.size() << endl;
    for (int i = 0; i < stu.size(); i++)
        cout << stu[i].number << " " << stu[i].final_rank << " " << stu[i].location << " " << stu[i].local_rank << endl;
    return 0;
}