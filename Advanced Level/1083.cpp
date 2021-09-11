#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    string name;
    string id;
    int grade;
} stu[105];

bool cmp(node n1, node n2)
{
    return n1.grade > n2.grade;
}

int main()
{
    int n, grade1, grade2, tag = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> stu[i].name >> stu[i].id >> stu[i].grade;
    cin >> grade1 >> grade2;
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (stu[i].grade >= grade1 && stu[i].grade <= grade2)
        {
            cout << stu[i].name << " " << stu[i].id << endl;
            tag = 1;
        }
    }
    if (tag == 0)
        cout << "NONE" << endl;
    return 0;
}