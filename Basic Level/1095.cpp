#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct type1
{
    string id;
    int grade;
};

bool cmp1(const type1 &t1, const type1 &t2)
{
    if (t1.grade != t2.grade)
        return t1.grade > t2.grade;
    else
        return t1.id < t2.id;
}

struct type2
{
    int count = 0;
    int total = 0;
};

bool cmp2(pair<string, int> t1, pair<string, int> t2)
{
    if (t1.second != t2.second)
        return t1.second > t2.second;
    else
        return t1.first < t2.first;
}

int main() //这题输出最初用的cout,测试点3超时,换成printf就直接过了,快了四倍
{
    map<string, vector<type1>> rec1;    //记录类型1
    map<string, type2> rec2;            //记录类型2
    map<string, map<string, int>> rec3; //记录类型3
    int n, m, point;
    string msg;
    type1 ty1;
    char id_msg[20];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", id_msg, &point);
        msg = id_msg;

        //类型1处理
        ty1.id = msg;
        ty1.grade = point;
        rec1[msg.substr(0, 1)].push_back(ty1);

        //类型2处理
        rec2[msg.substr(1, 3)].count += 1;
        rec2[msg.substr(1, 3)].total += point;

        //类型3处理
        rec3[msg.substr(4, 6)][msg.substr(1, 3)] += 1;
    }

    //对rec1各等级排序
    map<string, vector<type1>>::iterator it;
    for (it = rec1.begin(); it != rec1.end(); it++)
        sort(it->second.begin(), it->second.end(), cmp1);

    int t;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %s", &t, id_msg);
        msg = id_msg;
        printf("Case %d: %d %s\n", i, t, id_msg);
        if (t == 1)
        {
            if (rec1.find(msg) == rec1.end())
                printf("NA\n");
            else
            {
                for (int j = 0; j < rec1[msg].size(); j++)
                    printf("%s %d\n", rec1[msg][j].id.c_str(), rec1[msg][j].grade);
            }
        }
        else if (t == 2)
        {
            if (rec2.find(msg) == rec2.end())
                printf("NA\n");
            else
                printf("%d %d\n", rec2[msg].count, rec2[msg].total);
        }
        else if (t == 3)
        {
            if (rec3.find(msg) == rec3.end())
                printf("NA\n");
            else
            {
                vector<pair<string, int>> vec;
                map<string, int>::iterator iter;
                for (iter = rec3[msg].begin(); iter != rec3[msg].end(); iter++)
                    vec.push_back(pair<string, int>(iter->first, iter->second));

                sort(vec.begin(), vec.end(), cmp2);
                for (int j = 0; j < vec.size(); j++)
                    printf("%s %d\n", vec[j].first.c_str(), vec[j].second);
            }
        }
    }
    return 0;
}