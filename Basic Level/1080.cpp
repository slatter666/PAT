#include <iostream>
#include <set>
using namespace std;

struct student
{
    string id;
    int gp = 0;    //在线编程分数
    int mid = -1;  //期中成绩
    int final = 0; //期末成绩,期末考试不参加肯定不能合格，合格却有没参加的考试肯定只能是期中没参加
    int g = 0;     //总评

    bool friend operator<(student x, student y)
    {
        if (x.g != y.g)
            return x.g > y.g;
        else
            return x.id < y.id;
    }
};

int main()
{
    set<student> stu;
    int p, m, n, grade;
    char id_num[20]; //为了用格式化读入,否则测试点3超时
    cin >> p >> m >> n;

    for (int i = 0; i < p; i++) //在线编程作业的学生分数
    {
        scanf("%s %d", id_num, &grade);
        if (grade >= 200)
        {
            student s;
            s.id = id_num;
            s.gp = grade;
            stu.insert(s);
        }
    }

    for (int i = 0; i < m; i++) //期中成绩
    {
        scanf("%s %d", id_num, &grade);
        student s;
        s.id = id_num;
        set<student>::iterator it = stu.find(s);
        if (it != stu.end())
        {
            s.mid = grade;
            s.gp = (*it).gp;
            stu.erase(it);
            stu.insert(s);
        }
    }

    for (int i = 0; i < n; i++) //期末成绩
    {
        scanf("%s %d", id_num, &grade);
        student s;
        s.id = id_num;
        set<student>::iterator it = stu.find(s);
        if (it != stu.end())
        {
            s.final = grade;
            s.gp = (*it).gp;
            s.mid = (*it).mid;
            if (s.mid > s.final)
                s.g = 0.4 * s.mid + 0.6 * s.final + 0.5;
            else
                s.g = s.final;
            stu.erase(it);
            if (s.g >= 60)
                stu.insert(s);
        }
    }

    set<student>::iterator it;
    for (it = stu.begin(); it != stu.end(); it++)
    {
        if ((*it).g >= 60) // 这里还需要判断是因为有的学生编程过了，期中有了，没有期末
            cout << (*it).id << " " << (*it).gp << " " << (*it).mid << " " << (*it).final << " " << (*it).g << endl;
    }
    return 0;
}