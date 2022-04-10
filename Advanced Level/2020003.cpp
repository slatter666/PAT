#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct node
{
    int id, cnt, total;
};

vector<node> result;
map<int, pair<int, int>> rec;   
map<int, int> student;
map<int, int> grade;

int find(int x)
{
    if (student.find(x) == student.end())
        student[x] = x;
    int root = x;
    while (root != student[root]) // 找根
        root = student[root];
    while (x != root) //路径压缩
    {
        int temp = student[x];
        student[x] = root;
        x = temp;
    }
    return root;
}

bool cmp(node n1, node n2)
{
    if (n1.total != n2.total)
        return n1.total > n2.total;
    else if (n1.cnt != n2.cnt)
        return n1.cnt < n2.cnt;
    else
        return n1.id < n2.id;
}

int main()
{
    int n, id, k, mate, score;
    cin >> n;
    while (n--)
    {
        cin >> id >> k;
        int root = find(id); // 为防止k=0要先把自己给处理了
        for (int i = 0; i < k; i++)
        {
            cin >> mate;
            int root1 = find(id), root2 = find(mate);
            if (root1 < root2) // 由于要求输出每个学校最小的一个学生，因此向id小的合并
                student[root2] = root1;
            else
                student[root1] = root2;
        }
        cin >> score;
        grade[id] = score;
    }

    for (auto it : student)
    {
        id = it.first;
        if (find(id) == id) // 是一个根
        {
            if (grade.find(id) != grade.end())
                rec[id] = {1, grade[id]};
            else
                rec[id] = {1, 0};
        }
        else // 不是根
        {
            int root = find(id);
            rec[root].first++;
            if (grade.find(id) != grade.end()) // 有分则加，无分就算了
                rec[root].second += grade[id];
        }
    }

    for (auto it : rec)
        result.push_back({it.first, it.second.first, it.second.second});
    sort(result.begin(), result.end(), cmp);
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
        printf("%04d %d %d\n", result[i].id, result[i].cnt, result[i].total);
    return 0;
}