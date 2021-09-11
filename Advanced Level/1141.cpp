#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct node
{
    string school;
    int rank;
    double ts = 0; // temp score  临时存放总成绩
    int tws;
    int ns = 0;
};

bool cmp(node n1, node n2)
{
    if (n1.tws != n2.tws) // 要根据整数成绩来排序而不是double那个
        return n1.tws > n2.tws;
    else if (n1.ns != n2.ns) // 这里手贱ns打成了tws找了一个小时的bug 艹艹艹
        return n1.ns < n2.ns;
    else
        return n1.school < n2.school;
}

int main()
{
    int n;
    double score;
    string id, sch;
    cin >> n;
    map<string, node> rec;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> score >> sch;
        transform(sch.begin(), sch.end(), sch.begin(), ::tolower); // 转化为小写
        if (id[0] == 'B')
            score /= 1.5;
        else if (id[0] == 'T')
            score *= 1.5;
        rec[sch].ts += score;
        rec[sch].ns++;
    }

    vector<node> ranklist;
    for (auto it : rec)
    {
        it.second.school = it.first;
        it.second.tws = it.second.ts; // 得到tws
        ranklist.push_back(it.second);
    }
    sort(ranklist.begin(), ranklist.end(), cmp);
    cout << ranklist.size() << endl;
    for (int i = 0; i < ranklist.size(); i++)
    {
        ranklist[i].rank = i + 1;
        if (i != 0 && ranklist[i].tws == ranklist[i - 1].tws) // 如果不用ts转tws而采用int(tws)==int(tws)最后个测试点过不去
            ranklist[i].rank = ranklist[i - 1].rank;
        printf("%d %s %d %d\n", ranklist[i].rank, ranklist[i].school.c_str(), ranklist[i].tws, ranklist[i].ns);
    }
    return 0;
}