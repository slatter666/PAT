#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
struct node
{
    string id;
    string name;
    int grade;
} stu[100005];

bool cmp(node n1, node n2)
{
    if (c == 1)
        return n1.id < n2.id;
    else if (c == 2)
        return n1.name != n2.name ? n1.name < n2.name : n1.id < n2.id;
    else if (c == 3)
        return n1.grade != n2.grade ? n1.grade < n2.grade : n1.id < n2.id;
}

int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> stu[i].id >> stu[i].name >> stu[i].grade;
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; i++)
        printf("%s %s %d\n", stu[i].id.c_str(), stu[i].name.c_str(), stu[i].grade); // 这题不用printf会超时，最后个测试点数据量有点大
    return 0;
}